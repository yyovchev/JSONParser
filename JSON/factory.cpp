#include "factory.h"

String Factory::jsFile;
int Factory::cur = 0;
int Factory::size = 0;

JSONObj* Factory::CreateFromFile(const char *filname)
{
    return CreateFromFile(String(filname));
}

JSONObj* Factory::CreateFromFile(const String &filename)
{
    std::fstream file(filename);

    if(!file.is_open())
       throw std::invalid_argument("File err");

    JSONObj* obj;
    jsFile = "";
    cur = 0;

    init(file);
    file.close();

    if(jsFile[cur] != '{')
        throw std::invalid_argument("invalid file content >> { exp");

    size = jsFile.getSize();

    obj = CreateJSONObject();

    return obj;
}

JSONType *Factory::CreateFromString(const char *string)
{
    return CreateFromString(String(string));
}

JSONType *Factory::CreateFromString(const String &string)
{
    JSONType* obj;

    cur = 0;
    initString(string);

    size = jsFile.getSize();

    obj = CreateNewItemValue();

    return obj;
}

JSONObj* Factory::CreateJSONObject()
{
    JSONObj *obj = new JSONObj;

    while(jsFile[cur] != '}')
    {
        if (cur >= size)
            throw std::invalid_argument ("Broken object");

        if (jsFile[cur] != ',' && jsFile[cur] != '{')
            throw std::invalid_argument ("Broken object");

        if(jsFile[cur + 1] == '}'){
            ++cur;
            break;
        }

        ++cur;
        String key = ItemKey();
        ++cur;
        JSONType* value = CreateNewItemValue();

        JSONItem item(key, value);
        delete value;

        try{
            obj->addItem(item);
        }
        catch(std::exception &e){
            std::cout<<e.what()<<std::endl;
        }
    }
    ++cur;
    return obj;
}

JSONType* Factory::CreateNewItemValue()
{
    JSONType* newValue;

    char ch = jsFile[cur];

    if(ch == '\"' || ch == '\'')
        newValue = CreateString();
    else if((ch >= '0' && ch <= '9') || ch =='.' || ch == '+' || ch == '-')
        newValue = CreateNumber();
    else if(ch == '{')
        newValue = CreateJSONObject();
    else if(ch >= 'a' && ch<='z')
        newValue = CreateWordType();
    else if(ch >= 'A' && ch<='Z')
        newValue = CreateWordType();
    else if(ch == '[')
        newValue = CreateArray();
    else
        throw std::invalid_argument("no match");

    return newValue;
}

String Factory::ItemKey()
{
    String key;
    while(jsFile[cur] != ':'){
        key += jsFile[cur];
        ++cur;
    }
    return key;
}

void Factory::init(std::istream &in)
{
    jsFile = "";
    char ch;
    bool instr = 0;
    while(!in.eof() && in.good()){
        in.get(ch);

        if (ch == '\"' && jsFile[jsFile.getSize()-1] != '\\')
            instr ^= 1;

        if (!in.eof())
            if (ch != '\n' && (ch !=' ' || instr))
               jsFile+=ch;
    }
}

TypeString* Factory::CreateString()
{
    String string;
    ++cur;
    // цикли докато не намери "
    // ако " участва в специален си то пред него ще има
    // само 1 '\'
    // Ако не намери " ще върти до края на json-а
    while(cur < size){
        char ch = jsFile[cur];

        if (ch == '\"' || ch == '\''){
            int br = 0;
            int i = cur-1;
            while (jsFile[i] == '\\' && i >0){
                --i;++br;
            }

            if (!br&0x1)
                break;
        }

        string += ch;
        ++cur;
    }

    ++cur;
    string += '\0';

    if(cur == size)
        throw std::invalid_argument("\" not found! ");

    TypeString* str = new TypeString(string);

    return str;
}

TypeNumber* Factory::CreateNumber()
{
    String number;

    char ch = jsFile[cur];

    int dot_br = 0;
    do{
        number+=ch;
        ++cur;
        ch = jsFile[cur];
    }while (cur < size && ch != ',' && ch != '}' && ch != ']');

    if(cur == size)
        std::invalid_argument("no end");
    int i=0;
    if (number[0]== '+' || number[0] == '-') ++i;
    int num_size = number.getSize();
    for(; i<num_size; ++i){
        if(number[i]=='.') ++dot_br;
        if (dot_br > 1 || ((number[i] < '0' || number[i]>'9')&&number[i]!='.')){
            throw std::invalid_argument(number + " is not numer");
        }
    }
    number.append('\0');
    double num = std::stod((char*)number);
    TypeNumber *numitem = new TypeNumber(num);
    return numitem;
}

JSONType* Factory::CreateWordType()
{
    String word;
    char ch = jsFile[cur];
    do{
        word+=ch;
        cur++;
        ch = jsFile[cur];
    }while(cur < size && ch != ',' && ch != '}' && ch != ']');

    int word_size = word.getSize();
    for(int i = 0; i<word_size; i++){
        char &ch = word[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
    }

    if (word == "null")
        return new TypeNULL;
    if(word == "true")
        return new TypeBool(true);
    if(word == "false")
        return new TypeBool(false);

    throw std::invalid_argument(word + " is not a vallid js type");

    return nullptr;
}

JSONArray* Factory::CreateArray(){
    JSONArray *arr = new JSONArray;

    while(jsFile[cur] != ']')
    {
        if (cur >= size)
            throw std::invalid_argument ("Broken object");

        if (jsFile[cur] != ',' && jsFile[cur] != '[')
            throw std::invalid_argument ("Broken array");

        if(jsFile[cur + 1] == ']'){
            ++cur;
            break;
        }

        ++cur;
        JSONType* value = CreateNewItemValue();

        arr->addItem(value);
        delete value;
    }
    ++cur;
    return arr;
}

void Factory::initString(const String &str)
{
    jsFile = "";
    char ch;
    bool instr = 0;
    int size = str.getSize();
    for(int i = 0;i<size; i++){
        ch = str[i];

        if (ch == '\"' && jsFile[jsFile.getSize()-1] != '\\')
            instr ^= 1;

        if (ch != '\n' && (ch !=' ' || instr))
           jsFile+=ch;
    }
}
