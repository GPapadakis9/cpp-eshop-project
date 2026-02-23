#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Computers : public Product {

int ram;
float cpu;
std::string disk_type;
int disk_space;
int graphics;

public:
	//constructor
	Computers(){}
	//constructor me orismata
	Computers(int ID,std::string model,std::string manufacturer,bool photo,
		std::string description,float price,int ram,float cpu,std::string disk_type,
		int disk_space,int graphics):Product(ID,model,manufacturer,photo,description,price){
		this->ram = ram;
		this->cpu = cpu;
		this->disk_type = disk_type;
		this->disk_space = disk_space;
		this->graphics = graphics;	
	}
	//constructor gia load apo file
		Computers(std::string strComputer){
			std::istringstream issin(strComputer);
			
			std::string split[11];
			int i = 0;
			while(getline(issin, split[i], '|')){
				i++;
			}
			std::istringstream ss(split[0]);
			std::istringstream ss1(split[3]);
			std::istringstream ss2(split[5]);
			std::istringstream ss3(split[6]);
			std::istringstream ss4(split[7]);
			std::istringstream ss5(split[8]);
			std::istringstream ss6(split[9]);
			std::istringstream ss7(split[10]);
			ss >> this->ID;
			this->model = split[1];
			this->manufacturer = split[2];
			ss1 >> this->photo;
			this->description = split[4];
			ss2 >> this->price;
			ss3 >> this->ram;
			ss4 >> this->cpu;
			ss5 >> this->disk_type;
			ss6 >> this->disk_space;
			ss7 >> this->graphics;
		}	
	//setters & getters
	void setRam(int ram){this->ram = ram;}
	void setCpu(float cpu){this->cpu = cpu;}
	void setDisk_type(std::string disk_type){this->disk_type = disk_type;}
	void setDisk_space(int disk_space){this->disk_space = disk_space;}
	void setGraphics(int graphics){this->graphics = graphics;}

	int getRam(){return ram;}
	float getCpu(){return cpu;}
	std::string getDisk_type(){return disk_type;}
	int getDisk_space(){return disk_space;}
	int getGraphics(){return graphics;}
	
	std::string toString() {
		std::ostringstream oss;
		std::string str = "";
		oss << ID << "|" << model << "|" << manufacturer << "|" << photo << "|" << description << "|" << price << "|" << ram << "|" << cpu << "|" << disk_type << "|" << disk_space << "|" << graphics;
		str = oss.str();
		return str;
	}
	void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
		
};
