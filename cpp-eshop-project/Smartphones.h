#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Smartphones : public Product {

float screen_size;
int battery_duration;
bool video_4d;

public:
	//constructor
	Smartphones(){}
	//constructor me orismata
	Smartphones(int ID,std::string model,std::string manufacturer,bool photo,
		std::string description,float price,float screen_size,
		int battery_duration,bool video_4d)
		:Product(ID,model,manufacturer,photo,description,price){
			
			this->screen_size = screen_size;
			this->battery_duration = battery_duration;
			this->video_4d = video_4d;	
	}
	//constructor gia load apo file
		Smartphones(std::string strSmartphone){
			std::istringstream issin(strSmartphone);
			
			std::string split[9];
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
			ss >> this->ID;
			this->model = split[1];
			this->manufacturer = split[2];
			ss1 >> this->photo;
			this->description = split[4];
			ss2 >> this->price;
			ss3 >> this->screen_size;
			ss4 >> this->battery_duration;
			ss5 >> this->video_4d;
			
		}
	//setters & getters
	void setScreen_size(float screen_size){this->screen_size = screen_size;}
	void setBattery_duration(int battery_duration){this->battery_duration = battery_duration;}
	void setVideo_4d(bool video_4d){this->video_4d = video_4d;}

	float getScreen_size(){return screen_size;}
	int getBattery_duration(){return battery_duration;}
	bool getVideo_4d(){return video_4d;}
	
	std::string toString() {
		std::ostringstream oss;
		std::string str = "";
		oss << ID << "|" << model << "|" << manufacturer << "|" << photo << "|" << description << "|" << price << "|" << screen_size << "|" << battery_duration << "|" << video_4d;
		str = oss.str();
		return str;
	}
	void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}

};
