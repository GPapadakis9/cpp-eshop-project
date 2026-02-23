#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Companies : public Customers{
	private:
		std::string brand;
		std::string name;
		std::string surname;
		int discount;
		int fax;
	public:
		//constructor
		Companies(){}
		//constructor me orismata
		Companies(std::string username,std::string password,
		int afm,int phone,std::string address,
		std::string brand,std::string name,std::string surname,
		int discount,int fax) : Customers(username,password,afm,phone,address){
			
			this->brand = brand;
			this->name = name;
			this->surname = surname;
			this->discount = discount;
			this->fax = fax;
			
		}
		//constructor gia load apo file
		Companies(std::string strCompany){
			std::istringstream issin(strCompany);
			
			std::string split[10];
			int i = 0;
			while(getline(issin, split[i], '|')){
				i++;
			}
			std::istringstream ss(split[2]);
			std::istringstream ss1(split[3]);
			std::istringstream ss2(split[8]);
			std::istringstream ss3(split[9]);
			
			this->username = split[0];
			this->password = split[1];
			ss >> this->afm;
			ss1 >> this->phone;
			this->address = split[4];
			this->brand = split[5];
			this->name = split[6];
			this->surname = split[7];
			ss2 >> this->discount;
			ss3 >> this->fax;
		}
		//setters & getters
		void setBrand(std::string brand){this->brand = brand;}
		void setName(std::string name){this->name = name;}
		void setSurname(std::string surname){this->surname = surname;}
		void setDiscount(int discount){this->discount = discount;}
		void setFax(int fax){this->fax = fax;}
	
		std::string getBrand(){return brand;}
		std::string getRep_name(){return name;}
		std::string getRep_surname(){return surname;}
		int getDiscount(){return discount;}
		int getFax(){return fax;}
		
		std::string toString() {
			std::ostringstream oss;
			std::string str = "";
			oss << username << "|" << password << "|" << afm << "|" << phone << "|" << address << "|" << brand << "|" << name << "|" << surname << "|" << discount << "|" << fax;
			str = oss.str();
			return str;
		}
		
		void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
		
		
};
