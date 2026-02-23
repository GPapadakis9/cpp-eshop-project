#include <string>
class Customers : public User{
	protected:
		int afm;
		int phone;
		std::string address;
	public:
		//constructor
		Customers(){}
		//constructor me orismata
		Customers(std::string username,std::string password,
		int afm,int phone,std::string address) : User(username,password){
			
			this->afm = afm;
			this->phone = phone;
			this->address = address;
			
		}
		//setters & getters
		void setAfm(int afm){this->afm = afm;}
		void setPhone(int phone){this->phone = phone;}
		void setAddress(std::string address){this->address = address;}
	
		int getAfm(){return afm;}
		int getPhone(){return phone;}
		std::string getAddress(){return address;}
	
		
	
};
