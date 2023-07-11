//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> mapa;
    std::string::iterator it=s.begin();
    while(it!=s.end())
    {
        if(((*it)>='0' && (*it)<='9') || ((*it)>='A' && (*it)<='Z') || ((*it)>='a' && (*it)<='z'))
        {
            auto pomocni=it;
            std::string sp;
            while((*it>='0' && *it<='9') || (*it>='A' && *it<='Z') || (*it>='a' && *it<='z'))
            {
                char k=*it;
                if(k>='A' && k<='Z')
                k=k+32;
                sp.push_back(k);
                if(it<s.end())
                it++;
                else break;
            }
            mapa[sp].insert(pomocni-s.begin());
        }


        if(it<s.end())
        it++;
        else
        break;
    }

    return mapa;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa);

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa)
{
    std::set<int> indeksi;
    if(!mapa.count(s))
    {
        throw std::logic_error("Unesena rijec nije nadjena!");
    }
    for(auto p=mapa.begin();p!=mapa.end();p++)
    {
        if(p->first==s)
        {
            indeksi=p->second;
        }
    }
    return indeksi;
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string str;
    std::getline(std::cin,str);
    auto mapa=KreirajIndeksPojmova(str);
    IspisiIndeksPojmova(mapa);
    do
    {
        std::cout<<"Unesite rijec:";
        std::string unesi;
        std::getline(std::cin,unesi);
        if(unesi==".")
        break;
        try
        {
        auto s=PretraziIndeksPojmova(unesi,mapa);
        for(auto l=s.begin();l!=s.end();l++)
        {
            std::cout<<" "<<*l;
        }
        }
        catch(std::logic_error greska)
        {
            std::cout<<" "<<greska.what();
        }
        std::cout<<std::endl;
    }
    while(1);
    return 0;

}



void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    for(auto p=mapa.begin();p!=mapa.end();p++)
    {
        std::cout<<p->first<<": ";
        int pom=p->second.size();
        for(auto r=p->second.begin();r!=p->second.end();r++)
        {
            pom--;
            std::cout<<*r;
            if(pom>0)
            std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
