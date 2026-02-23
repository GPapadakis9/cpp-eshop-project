#include <string>
#include <vector>
#include <utility>

class Orders {
	private:
		int order_id;
		int customer_afm;
		std::vector<std::pair<Product,int> > cart;
		float order_cost;
		std::string order_status;
	
	public:
		//constructor
		Orders(){}
		//constructor me orismata
		Orders(int order_id,int customer_afm,std::vector<std::pair<Product,int> > &cart,float order_cost,std::string order_status){
			
			this->order_id = order_id;
			this->customer_afm = customer_afm;
			this->cart = cart;
			this->order_cost = order_cost;
			this->order_status = order_status;
			
		}
		
		//setters & getters
		void setOrder_id(int order_id){this->order_id = order_id;}
		void setCustomer_afm(int customer_afm){this->customer_afm = customer_afm;}
		void setCart(std::vector<std::pair<Product,int> > &cart){this->cart = cart;}
		void setOrder_cost(float order_cost){this->order_cost = order_cost;}
		void setOrder_status(std::string order_status){this->order_status = order_status;}
		
		int getOrder_id(){return order_id;}
		int getCustomer_afm(){return customer_afm;}
		std::vector<std::pair<Product,int> > getCart(){return cart;}
		float getOrder_cost(){return order_cost;}
		std::string getOrder_status(){return order_status;}
	
	
};
