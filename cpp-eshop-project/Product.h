#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Product {
	protected:
	int ID;
	std::string model;
	std::string manufacturer;
	bool photo;
	std::string description;
	float price;
	
	public:
		//constructor
		Product(){}
		//constructor me orismata
		Product(int ID,std::string model,std::string manufacturer,bool photo,
		std::string description,float price){
			
			this->ID = ID;
			this->model = model;
			this->manufacturer = manufacturer;
			this->photo = photo;
			this->description = description;
			this->price = price;
			
			}
		//constructor gia load apo file
		Product(std::string strProduct){
			std::istringstream issin(strProduct);
			
			std::string split[6];
			int i = 0;
			while(getline(issin, split[i], '|')){
				i++;
			}
			std::istringstream ss(split[0]);
			std::istringstream ss1(split[3]);
			std::istringstream ss2(split[5]);
			ss >> this->ID;
			this->model = split[1];
			this->manufacturer = split[2];
			ss1 >> this->photo;
			this->description = split[4];
			ss2 >> this->price;
			
		}	
		
		
		//setters & getters
		void setID(int ID){this->ID = ID;}
		void setModel(std::string model){this->model = model;}
		void setManufacturer(std::string manufacturer){this->manufacturer = manufacturer;}
		void setPhoto(bool photo){this->photo = photo;}
		void setDescription(std::string description){this->description = description;}
		void setPrice(float price){this->price = price;}
		
		int getID(){return ID;}
		std::string getModel(){ return model;}
		std::string getManufacturer(){return manufacturer;}
		bool getPhoto(){return photo;}
		std::string getDescription(){return description;}
		float getPrice(){return price;}
		
		std::string toString() {
			std::ostringstream oss;
			std::string str = "";
			oss << ID << "|" << model << "|" << manufacturer << "|" << photo << "|" << description << "|" << price;
			str = oss.str();
			return str;
		}
		
		void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
		
};
