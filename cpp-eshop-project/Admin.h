#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Admin : public User{
	
	
	
	public:
		//constructor
		Admin(){}
		//constructor me orismata
		Admin(std::string username,std::string password) : User(username,password){}
		//constructor gia load apo file
		Admin(std::string strAdmin){
			
			std::istringstream issin(strAdmin);
			std::string split[2];
			int i = 0;
			while(getline(issin, split[i], '|')){
				i++;
			}

			this->username = split[0];
			this->password = split[1];
			
		}	
	
		std::string toString() {
			std::ostringstream oss;
			std::string str = "";
			oss << username << "|" << password;
			str = oss.str();
			return str;
		}
		
		void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
	
		
};
