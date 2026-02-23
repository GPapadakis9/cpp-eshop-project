#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Individuals : public Customers{
	private:
		std::string name;
		std::string surname;
		std::string id_num;
	public:
		//constructor
		Individuals(){}
		//constructor me orismata
		Individuals(std::string username,std::string password,int afm,int phone,
		std::string address,std::string name,std::string surname,
		std::string id_num) : Customers(username,password,afm,phone,address){
			
			this->name = name;
			this->surname = surname;
			this->id_num = id_num;
		
		}
		//constructor gia load apo file
		Individuals(std::string strIndividual){
			std::istringstream issin(strIndividual);
			
			std::string split[8];
			int i = 0;
			while(getline(issin, split[i], '|')){
				i++;
			}
			std::istringstream ss(split[2]);
			std::istringstream ss1(split[3]);
			
			this->username = split[0];
			this->password = split[1];
			ss >> this->afm;
			ss1 >> this->phone;
			this->address = split[4];
			this->name = split[5];
			this->surname = split[6];
			this->id_num = split[7];
			
		}
		//setters & getters	
		void setName(std::string name){this->name = name;}
		void setSurname(std::string surname){this->surname = surname;}
		void setId_num(std::string id_num){this->id_num = id_num;}
	
		std::string getName(){return name;}
		std::string getSurname(){return surname;}
		std::string getId_num(){return id_num;}	
		
		std::string toString() {
			std::ostringstream oss;
			std::string str = "";
			oss << username << "|" << password << "|" << afm << "|" << phone << "|" << address << "|" << name << "|" << surname << "|" << id_num;
			str = oss.str();
			return str;
		}
		
		void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
	
};
