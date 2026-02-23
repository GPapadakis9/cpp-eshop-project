#include <string>

class User {
	protected:
		std::string username;
		std::string password;
	public:
		//constructor
		User(){}
		//constructor me orismata
		User(std::string username,std::string password){
			
			this->username = username;
			this->password = password;
			
		}
		//setters & getters
		void setUsername(std::string username){this->username = username;}
		void setPassword(std::string password){this->password = password;}
	
		std::string getUsername(){return username;}
		std::string getPassword(){return password;}
	
	
};
