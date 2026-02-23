#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class TV : public Product {

int diagwnios;
std::string company;
bool view_3d;

public:
	//constructor
	TV(){}
	//constructor me orismata
	TV(int ID,std::string model,std::string manufacturer,bool photo,
		std::string description,float price,int diagwnios,std::string company
		,bool view_3d):Product(ID,model,manufacturer,photo,description,price){
			
		this->diagwnios = diagwnios;
		this->company = company;
		this->view_3d = view_3d;	
	}
	//constructor gia load apo file
		TV(std::string strTV){
			std::istringstream issin(strTV);
			
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
			ss3 >> this->diagwnios;
			ss4 >> this->company;
			ss5 >> this->view_3d;
			
		}	
	//setters & getters
	void setDiagwnios(int diagwnios){this->diagwnios = diagwnios;}
	void setCompany(std::string company){this->company = company;}
	void setView_3d(bool view_3d){this->view_3d = view_3d;}

	int getDiagwnios(){return diagwnios;}
	std::string getCompany(){return company;}
	bool getView_3d(){return view_3d;}

	std::string toString() {
		std::ostringstream oss;
		std::string str = "";
		oss << ID << "|" << model << "|" << manufacturer << "|" << photo << "|" << description << "|" << price << "|" << diagwnios << "|" << company << "|" << view_3d;
		str = oss.str();
		return str;
	}
	void save(std::ofstream &outfile) {
			outfile << this->toString() << "\n";
		}
	
};
