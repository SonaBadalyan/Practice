#include<iostream>
#include<string>

class Person
{
    public:

        Person() // may be compiler generated
        {
            // Եթե մենք ունենք գեթ մեկ կոնստրուկտոր, ապա կոմպիլյատոռը չի գենեռացնի դեֆոլտ կոնստրուկտոր։
            // Եթե ուզում ենք ստիպել կոմպիլյատոռին, որ գենեռացնի, ապա կարող ենք օգտվել  Person() = default; գրելաձևից։
            // Կարող ենք նաև ստիպել կոմպիլյատոռին, որ չգենեռացնի Person() = delete; գրելաձևով։
            // delete և default սինտաքսը կարելի է կիրառել կեմպիլյատեռի կողմից գենեռացված օբյեկտի կյանքը կառավարող յուրաքանչյուր ֆունկցիայի վրա։

            std::cout << "default constructor " << this <<  std::endl;
        }

        Person(const Person& other) // may be compiler generated
        {
            // Ի տարբերություն գենեռացված դեֆոլտ կոնստրուկտորի, որը հատուկ ոչինչ չի անում, դեֆոլտ քոփի կոնստրուկտորը օբյեկտի բոլոր դաշտերը ինիցալիզացնում է արգումենտ օբյեկտի դաշտերի արժեքներով, բիթ առ բիթ քոփի է անում։
            // Դա ըստ էության բավարար է, երբ օբյեկտի դաշտերը չունեն հիփի հետ աշխատող փոինթեռ, որի ալոկացումն ու դեալոկացումը ծրագրավորողի պատասխանատվությունն է։
            // Երբ ունենք փոինթեռ ու հիփից վերցրված հիշողության տարածք, ապա դեֆոլտ քոփի կոնստրուկտորը քոփի կանի միայն փոինթեռի արժեքը, իսկ հիփի օբյեկտը քոփի չի լինի։ Արդյունքում կունենանք երկու հատ փոինթեռ, մեկ օբյեկտի վրա։ Ինչը վտանգավոր երևույթ է։
            
            std::cout << "copy constructor "  << this << std::endl;
        }

        Person(int age, std::string name) : m_age(age), m_name(name)
        {
            // Յուրաքանչյուր կոնստրուկտոր, որը ունի պառամետրեր, կոչվում է արգորմենտով կոնստրուկտոր։ Արգումենտով կոնստրուկտորների տարատեսակ են նաև քոտի, մուվ կոնստրուկտորները։
            // Միայն քոփի, մուվ կոնտրուկտորներն են գենեռացվորմ, մնացած արգումենտով կոնստրուկտորների տարատեսակները դեֆոլտ գենեռացվող չեն։ Եթե ծրագարավողը ցանականում է ունենալ, ապա պիտի գրի։
            
            std::cout << "constructor with parameters "  << this << std::endl;
        }

        Person(Person&& other) // may be compiler generated
        {
            // Մուվ կոնստրուկտորի իմաստը ժամանակավոր օբյեկտները քոփի անելու փոխարեն տեղափոխելն է, այդպիսով բարձրացնելուվ ծրագրի արտադրողականությունը։
            // Ժամանակավոր են այն օբյեկտները, որոնք հիշողության մեջ կան, տեղ զբաղեցնորմ են, ինչպես բոլոր օբյեկտները, բայց ուղղակիորեն դիմել հնարավոր չի, քանի որ չունեն lvalue ռեֆեռերնս։
            // Դրա փոխարեն կարող ենք հղվել rvalue ռեֆերենսի միջոցով։

            std::cout << "move constructor " << this <<  std::endl;
        }

        Person& operator=(const Person& rhs) // may be compiler generated, it is not mandatory to return Person& and to have const Person& argument, we may have any return type and argumnet list
        {
            std::cout << "operator= " << this << std::endl;
            return *this;
        }

        Person& operator=(Person&& rhs) // may be compiler generated
        {
            std::cout << "move operator= " << this << std::endl;
            return *this;
        }

        ~Person() // may be compiler generated, it must have one definition per class
        {
            // Դեստրուկտորը չի վերադարձնում ոչ մի արժեք, չի ընդունում ոչ մի պարամետր, միակն է կլասի համար, նախատեսված է զբաղեցված ռեսուրսները ազատելոր համար։
            
            std::cout << "destructor "  << this << std::endl;
        }

    private:
        int m_age = 0;
        std::string m_name;
};

void test(Person p)
{
    std::cout << "_____________________" <<std::endl;
    std::cout << "Inside test " << std::endl;
    
}

Person test1(Person ob)
{
    std::cout << "_____________________" <<std::endl;
    std::cout << "Inside test1 " << std::endl;

    Person temp;
    temp = ob;
    return temp;
}

int main()
{
    Person ob;
    Person ob2(ob);
    Person ob3 = ob2;
    ob = ob3;

    std::cout << "_____________________" <<std::endl;

    Person ob4(Person());

    //Person *p = new Person();

    std::cout << "_____________________" <<std::endl;
    test(ob);

    std::cout << "_____________________" <<std::endl;
    Person person = test1(ob);
    

    std::cout << "Sizeof person class " << sizeof(Person) << std::endl;
    std::cout << "Sizeof person object " << sizeof(ob) << std::endl;
    std::cout << "Sizeof int " << sizeof(int) << std::endl;
    std::cout << "Sizeof string " << sizeof(std::string) << std::endl;

    return 0;
}