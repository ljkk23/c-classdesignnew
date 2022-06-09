#include <iostream>
#include <string>
using namespace std;
class Kvalue
{
public:
   string key;
   string data;
   int value;
   string toString(){
       return this->key+","+this->data+","+std::to_string(this->value);
   }
   void setKey(string key){
       this->key=key;
   }
   string getKey(){
        return this->key;
   }
   void setData(string data){
       this->data=data;
   }
   string getData(){
        return this->data;
   }
   void setValue(int value){
       this->value=value;
   }
   int getValue(string key){
       return this->value;
   }
   bool operator>(const Kvalue& b)
      {
         if (this->value>b.value)
         {
             /* code */
             return true;
         }else
         return false;
      }
    bool operator!=(const Kvalue& b)
      {
         if (this->key.compare(b.key))
         {
             /* code */
             return true;
         }else
         return false;
      }
    Kvalue(int value,string key,string data)
    {
        this->setKey(key);
        this->setValue(value);
        this->setData(data);
        }
    Kvalue(){};
    Kvalue(string key){
        this->data=" ";
        this->key=key;
        this->value=0;
    };
    Kvalue(string key,string data){
        this->data=data;
        this->key=key;
    }
    Kvalue(string key,int value){
        this->value=value;
        this->key=key;
    }
    Kvalue(string key,string value,int valueID){
        this->data=value;
        this->key=key;
        this->value=valueID;
    }
    friend ostream&  operator<<(ostream& os, const Kvalue& kvalue)
        {
            os << kvalue.value<<","<< kvalue.key << "," << kvalue.data<<")";
            return os;
        }
    ~Kvalue(){
        cout<<"xigou\n";
    };
};





