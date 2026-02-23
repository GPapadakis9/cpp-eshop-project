#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "Product.h"
#include "Computers.h"
#include "Smartphones.h"
#include "TV.h"
#include "User.h"
#include "Customers.h"
#include "Admin.h"
#include "Individuals.h"
#include "Companies.h"
#include "Orders.h"

void readProducts(std::vector<Product> &products);
void readSmartphones(std::vector<Smartphones> &smartphones);
void readComputers(std::vector<Computers> &computers);
void readTV(std::vector<TV> &tvs);
void writeProducts(std::vector<Product> &products);
void writeSmartphones(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs);
void writeComputers(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs);
void writeTV(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs);
void readAdmin(std::vector<Admin> &admins);
void readIndividuals(std::vector<Individuals> &individuals);
void readCompanies(std::vector<Companies> &companies);
void writeAdmin(std::vector<Admin> &admins);
void writeIndividuals(std::vector<Individuals> &individuals,std::vector<Companies> &companies);
void writeCompanies(std::vector<Individuals> &individuals,std::vector<Companies> &companies);
void printProducts(std::vector<Product> &products);
void printSmartphones(std::vector<Smartphones> &smartphones);
void printComputers(std::vector<Computers> &computers);
void printTV(std::vector<TV> &tvs);
void deleteProducts(std::vector<Product> &products);
void deleteSmartphones(std::vector<Smartphones> &smartphones);
void deleteComputers(std::vector<Computers> &computers);
void deleteTV(std::vector<TV> &tvs);
void modifyProducts(std::vector<Product> &products);
void modifySmartphones(std::vector<Smartphones> &smartphones);
void modifyComputers(std::vector<Computers> &computers);
void modifyTV(std::vector<TV> &tvs);
void addtoProducts(std::vector<Product> &products,std::vector<std::pair<Product,int> > &cart);
void addtoSmartphones(std::vector<Smartphones> &smartphones,std::vector<std::pair<Product,int> > &cart);
void addtoComputers(std::vector<Computers> &computers,std::vector<std::pair<Product,int> > &cart);
void addtoTV(std::vector<TV> &tvs,std::vector<std::pair<Product,int> > &cart);
void printCart(std::vector<std::pair<Product,int> > &cart);
void deletefromCart(std::vector<std::pair<Product,int> > &cart);
void makeOrder(int afm,std::vector<std::pair<Product,int> > &cart,std::vector<Orders> &orders);
void makeDorder(int discount,int afm,std::vector<std::pair<Product,int> > &cart,std::vector<Orders> &orders);
void modifyOrderStatus(std::vector<Orders> &orders);
void printOrders(std::vector<Orders> &orders);
void printIndividuals(std::vector<Individuals> &individuals);
void printCompanies(std::vector<Companies> &companies);
void printOrderStatus(int afm,std::vector<Orders> &orders);

int main(int argc, char** argv) {
	
	std::vector<Product> products;
	std::vector<Smartphones> smartphones;
	std::vector<Computers> computers;
	std::vector<TV> tvs;
	std::vector<Admin> admins;
	std::vector<Individuals> individuals;
	std::vector<Companies> companies;
	std::vector<std::pair<Product,int> > cart;
	std::vector<Orders> orders;
	std::string user;
	std::string pass;
	int afm;
	int discount;
	bool check;
	char select;
	char action;
	bool x,y,z,w,q,f;
	std::string back;
	//initial loading
	readProducts(products);
	readSmartphones(smartphones);
	readComputers(computers);
	readTV(tvs);
	readAdmin(admins);
	readIndividuals(individuals);
	readCompanies(companies);	
	//kentriko loop
	x = true;
	while(x){
		//admin or user select
		std::cout << "Type '1' for ADMIN login or '2' for USER login or '0' to EXIT.\n";
		std::cin >> select;
		
		switch(select){
			case '0' :
				std::cout << "----------------Goodbye!----------------\n\n";
				x = false;
				break;
			case '1' :
				//admin stuff
				y = true;
				while(y){
				
				std::cout << "Please type your username:";
				std::cin >> user;
				std::cout << "\n";
				std::cout << "Please type your password:";
				std::cin >> pass;
				std::cout << "\n";
				std::cout << std::string(50, '\n');
				check = false;
				for (int i = 0; i < admins.size(); i++) {
					
					if(user == admins[i].getUsername() && pass == admins[i].getPassword()){
					
						std::cout << "----------------Welcome to Eshop----------------\n\n";
						check = true;
						break;
					}
				}
				if(check){
					//leitourgies admin
					z = true;
					while(z){
						std::cout << "Please type the number for the action you want to do.\n\n";
						std::cout << "1: Create new user account.\n";
						std::cout << "2: Show all available products.\n";
						std::cout << "3: Add new product.\n";
						std::cout << "4: Delete a product.\n";
						std::cout << "5: Modify a product.\n";
						std::cout << "6: Modify order status.\n";
						std::cout << "7: Show all customers.\n";
						std::cout << "8: Show orders  & order status per customer.\n";
						std::cout << "0: Logout.\n";
						std::cin >> action;
						switch(action){
							case '0' :
								std::cout << std::string(50, '\n');
								std::cout << "--------Logged out of the system--------\n\n";
								y = false;
								z = false;
								break;
							case '1' :
								//create new account
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Create new administrator account.\n";
								std::cout << "2: Create new individual account.\n";
								std::cout << "3: Create new company account.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										writeAdmin(admins);
										std::cout << "--------Account created succesfully!--------\n";
										continue;
									case '2' :
										writeIndividuals(individuals,companies);
										std::cout << "--------Account created succesfully!--------\n";
										continue;
									case '3' :
										writeCompanies(individuals,companies);
										std::cout << "--------Account created succesfully!--------\n";
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
								}
							case '2' :
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Show available smartphones.\n";
								std::cout << "2: Show available computers.\n";
								std::cout << "3: Show available TVs.\n";
								std::cout << "4: Show all available products.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										std::cout << std::string(50, '\n');
										printSmartphones(smartphones);
										continue;
									case '2' :
										std::cout << std::string(50, '\n');
										printComputers(computers);
										continue;
									case '3' :
										std::cout << std::string(50, '\n');
										printTV(tvs);
										continue;
									case '4' :
										std::cout << std::string(50, '\n');
										printSmartphones(smartphones);
										printComputers(computers);
										printTV(tvs);
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
								}
								
							case '3' :
								//add new product
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Create new Smartphone.\n";
								std::cout << "2: Create new Computer.\n";
								std::cout << "3: Create new TV.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										writeSmartphones(smartphones,computers,tvs);
										std::cout << std::string(50, '\n');
										printSmartphones(smartphones);
										continue;
									case '2' :
										writeComputers(smartphones,computers,tvs);
										std::cout << std::string(50, '\n');
										printComputers(computers);
										continue;
									case '3' :
										writeTV(smartphones,computers,tvs);
										std::cout << std::string(50, '\n');
										printTV(tvs);
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
								}
							case '4' :
								//delete product
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Delete a Smartphone by ID.\n";
								std::cout << "2: Delete a Computer by ID.\n";
								std::cout << "3: Delete a TV by ID.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										printSmartphones(smartphones);
										deleteSmartphones(smartphones);
										std::cout << std::string(50, '\n');
										printSmartphones(smartphones);
										continue;
									case '2' :
										printComputers(computers);
										deleteComputers(computers);
										std::cout << std::string(50, '\n');
										printComputers(computers);
										continue;
									case '3' :
										printTV(tvs);
										deleteTV(tvs);
										std::cout << std::string(50, '\n');
										printTV(tvs);
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
								}
							case '5' :
								//modify product
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Modify a Smartphone by ID.\n";
								std::cout << "2: Modify a Computer by ID.\n";
								std::cout << "3: Modify a TV by ID.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										modifySmartphones(smartphones);
										std::cout << std::string(50, '\n');
										printSmartphones(smartphones);
										continue;
									case '2' :
										modifyComputers(computers);
										std::cout << std::string(50, '\n');
										printComputers(computers);
										continue;
									case '3' :
										modifyTV(tvs);
										std::cout << std::string(50, '\n');
										printTV(tvs);
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
								}
							case '6' :
								//modify order status
								std::cout << std::string(50, '\n');
								if(orders.size()>0){
									modifyOrderStatus(orders);
									continue;
								}
								else{
									std::cout << "----------The are no orders placed----------\n\n";
									continue;
								}
							case '7' :
								//show all customers
								std::cout << std::string(50, '\n');
								std::cout << "0: Go back to main menu.\n";
								std::cout << "1: Show individual customers.\n";
								std::cout << "2: Show company customers.\n";
								std::cout << "3: Show all customers.\n";
								std::cin >> action;
								switch(action){
									case '0' :
										std::cout << std::string(50, '\n');
										continue;
									case '1' :
										std::cout << std::string(50, '\n');
										printIndividuals(individuals);
										continue;
									case '2' :
										std::cout << std::string(50, '\n');
										printCompanies(companies);
										continue;
									case '3' :
										std::cout << std::string(50, '\n');
										printIndividuals(individuals);
										printCompanies(companies);
										continue;
									default :
										std::cout << std::string(50, '\n');
										std::cout << "--------Invalid selection , Please try again--------\n\n";
										continue;
									}
							case '8' :
								//show all orders & order status per customer
								std::cout << std::string(50, '\n');
								if(orders.size()>0){
									printIndividuals(individuals);
									printCompanies(companies);
									printOrders(orders);
									continue;
								}
								else{
									std::cout << "----------The are no orders placed----------\n\n";
									continue;
								}
							default :
								std::cout << std::string(50, '\n');
								std::cout << "--------Invalid selection , Please try again--------\n\n";
						}
					}
				}
				else{
				
					std::cout << "Invalid username or password. Type any key to try again or '0' to select another MAIN user type.\n\n";
					std::cin >> back;
					if(back == "0"){
						break;
					}
					continue;
				}
				
			}
			break;
			case '2' :
				//user or company select
				w = true;
				while(w){
				std::cout << "Type '1' for Individual User or '2' for Company or '0' to select another MAIN user type.\n";
				std::cin >> select;
				
				switch(select){
					case '0' :
						w = false;
						break;
					case '1' :
						//individual user stuff
						q = true;
						while(q){
				
						std::cout << "Please type your username:";
						std::cin >> user;
						std::cout << "\n";
						std::cout << "Please type your password:";
						std::cin >> pass;
						std::cout << "\n";
						std::cout << std::string(50, '\n');
						check = false;
						for (int i = 0; i < individuals.size(); i++) {
					
							if(user == individuals[i].getUsername() && pass == individuals[i].getPassword()){
					
								std::cout << "----------------Welcome to Eshop----------------\n\n";
								afm = individuals[i].getAfm();
								check = true;
								break;
							}
						}
						if(check){
						//leitourgies aplou xristi
						f = true;
						while(f){
							std::cout << "Please type the number for the action you want to do.\n\n";
							std::cout << "1: Show all available products.\n";
							std::cout << "2: Add product to shopping cart.\n";
							std::cout << "3: Show all contents of the shopping cart.\n";
							std::cout << "4: Remove a product from the shopping cart.\n";
							std::cout << "5: Make an order.\n";
							std::cout << "6: Show order status.\n";
							std::cout << "0: Logout.\n";
							std::cin >> action;
							switch(action){
								case '0' :
									std::cout << std::string(50, '\n');
									std::cout << "--------Logged out of the system--------\n\n";
									cart.clear();
									q = false;
									f = false;
									w = false;
									break;
								case '1' :
									//Show all available products
									std::cout << std::string(50, '\n');
									std::cout << "0: Go back to main menu.\n";
									std::cout << "1: Show available smartphones.\n";
									std::cout << "2: Show available computers.\n";
									std::cout << "3: Show available TVs.\n";
									std::cout << "4: Show all available products.\n";
									std::cin >> action;
									switch(action){
										case '0' :
											std::cout << std::string(50, '\n');
											continue;
										case '1' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											continue;
										case '2' :
											std::cout << std::string(50, '\n');
											printComputers(computers);
											continue;
										case '3' :
											std::cout << std::string(50, '\n');
											printTV(tvs);
											continue;
										case '4' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											printComputers(computers);
											printTV(tvs);
											continue;
										default :
											std::cout << std::string(50, '\n');
											std::cout << "--------Invalid selection , Please try again--------\n\n";
											continue;
									}
								case '2' :
									//Add product to the shopping cart
									std::cout << std::string(50, '\n');
									std::cout << "0: Go back to main menu.\n";
									std::cout << "1: Add a Smartphone by ID.\n";
									std::cout << "2: Add a Computer by ID.\n";
									std::cout << "3: Add a TV by ID.\n";
									std::cin >> action;
									switch(action){
										case '0' :
											std::cout << std::string(50, '\n');
											continue;
										case '1' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											addtoSmartphones(smartphones,cart);
											continue;
										case '2' :
											std::cout << std::string(50, '\n');
											printComputers(computers);
											addtoComputers(computers,cart);
											continue;
										case '3' :
											std::cout << std::string(50, '\n');
											printTV(tvs);
											addtoTV(tvs,cart);
											continue;
										default :
											std::cout << std::string(50, '\n');
											std::cout << "--------Invalid selection , Please try again--------\n\n";
											continue;
									}
								case '3' :
									//Show contents of cart
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
										printCart(cart);
										continue;
									}
									else{
										std::cout << "----------Your shopping cart is empty----------\n\n";
										continue;
									}
								case '4' :
									//Remove product from cart
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
										printCart(cart);
										deletefromCart(cart);
										printCart(cart);
										continue;
									}
									else{
										std::cout << "--------Your shopping cart is already empty--------\n\n";
										continue;
									}
								case '5' :
									//Make an order
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
									makeOrder(afm,cart,orders);
									std::cout << "----------Thank you for your order----------\n\n";
									cart.clear();
									continue;
									}
									else{
										std::cout << "Your cart is empty, Add a product to your cart before you place an order\n\n";
										continue;
									}
								case '6' :
									//Show order status
									std::cout << std::string(50, '\n');
									printOrderStatus(afm,orders);
									continue;
								default :
									std::cout << std::string(50, '\n');
									std::cout << "--------Invalid selection , Please try again--------\n\n";
									continue;
								}
							}
						}
						else{
				
							std::cout << "Invalid username or password. Type any key to try again or '0' to select another user type.\n";
							std::cin >> back;
							if(back == "0")
								break;
							continue;
						}
							
					}
					break;
					case '2' :
						//company user stuff
						q = true;
						while(q){
				
						std::cout << "Please type your username:";
						std::cin >> user;
						std::cout << "\n";
						std::cout << "Please type your password:";
						std::cin >> pass;
						std::cout << "\n";
						std::cout << std::string(50, '\n');
						check = false;
						for (int i = 0; i < companies.size(); i++) {
					
							if(user == companies[i].getUsername() && pass == companies[i].getPassword()){
					
								std::cout << "----------------Welcome to Eshop----------------\n\n";
								afm = companies[i].getAfm();
								discount = companies[i].getDiscount();
								check = true;
								break;
							}
						}
						if(check){
						//leitourgies ekproswpou etairias
						f = true;
						while(f){
							std::cout << "Please type the number for the action you want to do.\n\n";
							std::cout << "1: Show all available products.\n";
							std::cout << "2: Add product to shopping cart.\n";
							std::cout << "3: Show all contents of the shopping cart.\n";
							std::cout << "4: Remove a product from the shopping cart.\n";
							std::cout << "5: Make an order.\n";
							std::cout << "6: Show order status.\n";
							std::cout << "0: Logout.\n";
							std::cin >> action;
							switch(action){
								case '0' :
									std::cout << std::string(50, '\n');
									std::cout << "--------Logged out of the system--------\n\n";
									cart.clear();
									q = false;
									f = false;
									w = false;
									break;
								case '1' :
									//Show all available products
									std::cout << std::string(50, '\n');
									std::cout << "0: Go back to main menu.\n";
									std::cout << "1: Show available smartphones.\n";
									std::cout << "2: Show available computers.\n";
									std::cout << "3: Show available TVs.\n";
									std::cout << "4: Show all available products.\n";
									std::cin >> action;
									switch(action){
										case '0' :
											std::cout << std::string(50, '\n');
											continue;
										case '1' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											continue;
										case '2' :
											std::cout << std::string(50, '\n');
											printComputers(computers);
											continue;
										case '3' :
											std::cout << std::string(50, '\n');
											printTV(tvs);
											continue;
										case '4' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											printComputers(computers);
											printTV(tvs);
											continue;
										default :
											std::cout << std::string(50, '\n');
											std::cout << "--------Invalid selection , Please try again--------\n\n";
											continue;
									}
								case '2' :
									//Add product to the shopping cart
									std::cout << std::string(50, '\n');
									std::cout << "0: Go back to main menu.\n";
									std::cout << "1: Add a Smartphone by ID.\n";
									std::cout << "2: Add a Computer by ID.\n";
									std::cout << "3: Add a TV by ID.\n";
									std::cin >> action;
									switch(action){
										case '0' :
											std::cout << std::string(50, '\n');
											continue;
										case '1' :
											std::cout << std::string(50, '\n');
											printSmartphones(smartphones);
											addtoSmartphones(smartphones,cart);
											continue;
										case '2' :
											std::cout << std::string(50, '\n');
											printComputers(computers);
											addtoComputers(computers,cart);
											continue;
										case '3' :
											std::cout << std::string(50, '\n');
											printTV(tvs);
											addtoTV(tvs,cart);
											continue;
										default :
											std::cout << std::string(50, '\n');
											std::cout << "--------Invalid selection , Please try again--------\n\n";
											continue;
									}
								case '3' :
									//Show contents of cart
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
										printCart(cart);
										continue;
									}
									else{
										std::cout << "----------Your shopping cart is empty----------\n\n";
										continue;
									}
								case '4' :
									//Remove product from cart
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
										printCart(cart);
										deletefromCart(cart);
										printCart(cart);
										continue;
									}
									else{
										std::cout << "--------Your shopping cart is already empty--------\n\n";
										continue;
									}
								case '5' :
									//Make an order
									std::cout << std::string(50, '\n');
									if(cart.size()>0){
										makeDorder(discount,afm,cart,orders);
										std::cout << "--------Thank you for your order--------\n\n";
										cart.clear();
										continue;
									}
									else{
										std::cout << "Your cart is empty, Add a product to your cart before you place an order\n\n";
										continue;
									}
								case '6' :
									//Show order status
									std::cout << std::string(50, '\n');
									printOrderStatus(afm,orders);
									continue;
								default :
									std::cout << std::string(50, '\n');
									std::cout << "--------Invalid selection , Please try again--------\n\n";
									continue;
								}
							}
						}
						else{
				
							std::cout << "Invalid username or password. Type any key to try again or '0' to select another user type.\n";
							std::cin >> back;
							if(back == "0")
								break;
							continue;
						}
				
						}
						break;
					default :
						//invalid user selection
						std::cout << "Invalid user type, Please try again.\n";
				}
			}
			break;
			default :
				//invalid user selection
				std::cout << "Invalid user type, Please try again.\n";
		}

			
	}
	
	
	
	
	
	

	
	


	return 0;
}

void readProducts(std::vector<Product> &products) {

	std::ifstream infile;
	infile.open("products.dat");

	std::string strProduct;

	while (infile.good()) {
		getline(infile, strProduct);
		if (strProduct.length() > 1) {
			products.push_back(Product(strProduct));
		}
	}

	infile.close();
}
void readSmartphones(std::vector<Smartphones> &smartphones) {

	std::ifstream infile;
	infile.open("smartphones.dat");

	std::string strSmartphone;

	while (infile.good()) {
		getline(infile, strSmartphone);
		if (strSmartphone.length() > 1) {
			smartphones.push_back(Smartphones(strSmartphone));
		}
	}

	infile.close();
}
void readComputers(std::vector<Computers> &computers) {

	std::ifstream infile;
	infile.open("computers.dat");

	std::string strComputer;

	while (infile.good()) {
		getline(infile, strComputer);
		if (strComputer.length() > 1) {
			computers.push_back(Computers(strComputer));
		}
	}

	infile.close();
}
void readTV(std::vector<TV> &tvs) {
	
	std::ifstream infile;
	infile.open("tvs.dat");

	std::string strTV;

	while (infile.good()) {
		getline(infile, strTV);
		if (strTV.length() > 1) {
			tvs.push_back(TV(strTV));
		}
	}

	infile.close();
}
void writeProducts(std::vector<Product> &products) {

	std::ofstream outfile;
	outfile.open("products.dat", std::ios::app);

	bool read = true;
	while (read) {
		Product product = Product();
		std::cout << "Please enter Product ID: " << "\n";
		int id;
		std::cin >> id;
		//check gia duplicate ID
		for(int i=0;i<products.size();i++){
				
			if(id==products[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				i = -1;
				std::cout << "Please enter Product ID: " << "\n";
				std::cin >> id;
				continue;
			}
		}
		product.setID(id);
		std::cout << "Please enter the model: " << "\n";
		std::string model;
		std::cin >> model;
		product.setModel(model);
		std::cout << "Please enter the manufacturer: " << "\n";
		std::string manufacturer;
		std::cin >> manufacturer;
		product.setManufacturer(manufacturer);
		std::cout << "Please enter '1' if a photo is available or '0' if not: " << "\n";
		bool photo;
		std::cin >> photo;
		product.setPhoto(photo);
		std::cout << "Please enter the description: " << "\n";
		std::string description;
		std::cin >> description;
		product.setDescription(description);
		std::cout << "Please enter the price: " << "\n";
		float price;
		std::cin >> price;
		product.setPrice(price);
		
		product.save(outfile);
		products.push_back(product);
		char action;
		std::cout << "Would you like to add another product? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void writeSmartphones(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs) {

	std::ofstream outfile;
	outfile.open("smartphones.dat", std::ios::app);

	bool read = true;
	while (read) {
		Smartphones smartphone = Smartphones();
		std::cout << "Please enter Smartphone ID: " << "\n";
		int id;
		std::cin >> id;
		//check gia duplicate ID
		bool x;
		bool y;
		y=false;
		x=true;
		while(x){
		for(int i=0;i<smartphones.size();i++){
				
			if(id==smartphones[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				i = -1;
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				continue;
			}
		}
		y=false;
		for(int i=0;i<computers.size();i++){
				
			if(id==computers[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		for(int i=0;i<tvs.size();i++){
				
			if(id==tvs[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		x=false;
		}
		smartphone.setID(id);
		std::cout << "Please enter the model: " << "\n";
		std::string model;
		std::cin >> model;
		smartphone.setModel(model);
		std::cout << "Please enter the manufacturer: " << "\n";
		std::string manufacturer;
		std::cin >> manufacturer;
		smartphone.setManufacturer(manufacturer);
		std::cout << "Please enter '1' if a photo is available or '0' if not: " << "\n";
		bool photo;
		std::cin >> photo;
		smartphone.setPhoto(photo);
		std::cout << "Please enter the description: " << "\n";
		std::string description;
		std::cin >> description;
		smartphone.setDescription(description);
		std::cout << "Please enter the price: " << "\n";
		float price;
		std::cin >> price;
		smartphone.setPrice(price);
		std::cout << "Please enter Screen Size: " << "\n";
		float screen;
		std::cin >> screen;
		smartphone.setScreen_size(screen);
		std::cout << "Please enter Battery Duration in hours: " << "\n";
		int battery;
		std::cin >> battery;
		smartphone.setBattery_duration(battery);
		std::cout << "Please enter '1' if 4D video is available or '0' if not: " << "\n";
		bool video;
		std::cin >> video;
		smartphone.setVideo_4d(video);
		
		smartphone.save(outfile);
		smartphones.push_back(smartphone);
		char action;
		std::cout << "Would you like to add another smartphone? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void writeComputers(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs) {

	std::ofstream outfile;
	outfile.open("computers.dat", std::ios::app);

	bool read = true;
	while (read) {
		Computers computer = Computers();
		std::cout << "Please enter Computer ID: " << "\n";
		int id;
		std::cin >> id;
		//check gia duplicate ID
		bool x;
		bool y;
		y=false;
		x=true;
		while(x){
		for(int i=0;i<smartphones.size();i++){
				
			if(id==smartphones[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				i = -1;
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				continue;
			}
		}
		y=false;
		for(int i=0;i<computers.size();i++){
				
			if(id==computers[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		for(int i=0;i<tvs.size();i++){
				
			if(id==tvs[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		x=false;
		}
		computer.setID(id);
		std::cout << "Please enter the model: " << "\n";
		std::string model;
		std::cin >> model;
		computer.setModel(model);
		std::cout << "Please enter the manufacturer: " << "\n";
		std::string manufacturer;
		std::cin >> manufacturer;
		computer.setManufacturer(manufacturer);
		std::cout << "Please enter '1' if a photo is available or '0' if not: " << "\n";
		bool photo;
		std::cin >> photo;
		computer.setPhoto(photo);
		std::cout << "Please enter the description: " << "\n";
		std::string description;
		std::cin >> description;
		computer.setDescription(description);
		std::cout << "Please enter the price: " << "\n";
		float price;
		std::cin >> price;
		computer.setPrice(price);
		std::cout << "Please enter RAM in GB: " << "\n";
		int ram;
		std::cin >> ram;
		computer.setRam(ram);
		std::cout << "Please enter CPU in GHz: " << "\n";
		float cpu;
		std::cin >> cpu;
		computer.setCpu(cpu);
		std::cout << "Please enter Disk type: " << "\n";
		std::string diskt;
		std::cin >> diskt;
		computer.setDisk_type(diskt);
		std::cout << "Please enter Disk Space in GB: " << "\n";
		int space;
		std::cin >> space;
		computer.setDisk_space(space);
		std::cout << "Please enter Graphics RAM in GB: " << "\n";
		int graphics;
		std::cin >> graphics;
		computer.setGraphics(graphics);
		
		computer.save(outfile);
		computers.push_back(computer);
		char action;
		std::cout << "Would you like to add another computer? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void writeTV(std::vector<Smartphones> &smartphones,std::vector<Computers> &computers,std::vector<TV> &tvs) {

	std::ofstream outfile;
	outfile.open("tvs.dat", std::ios::app);

	bool read = true;
	while (read) {
		TV tv = TV();
		std::cout << "Please enter TV ID: " << "\n";
		int id;
		std::cin >> id;
		//check gia duplicate ID
		bool x;
		bool y;
		y=false;
		x=true;
		while(x){
		for(int i=0;i<smartphones.size();i++){
				
			if(id==smartphones[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				i = -1;
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				continue;
			}
		}
		y=false;
		for(int i=0;i<computers.size();i++){
				
			if(id==computers[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		for(int i=0;i<tvs.size();i++){
				
			if(id==tvs[i].getID()){
				std::cout << "A product with this ID already exists. Please try another ID.\n";
				std::cout << "Please enter Smartphone ID: " << "\n";
				std::cin >> id;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		x=false;
		}
		tv.setID(id);
		std::cout << "Please enter the model: " << "\n";
		std::string model;
		std::cin >> model;
		tv.setModel(model);
		std::cout << "Please enter the manufacturer: " << "\n";
		std::string manufacturer;
		std::cin >> manufacturer;
		tv.setManufacturer(manufacturer);
		std::cout << "Please enter '1' if a photo is available or '0' if not: " << "\n";
		bool photo;
		std::cin >> photo;
		tv.setPhoto(photo);
		std::cout << "Please enter the description: " << "\n";
		std::string description;
		std::cin >> description;
		tv.setDescription(description);
		std::cout << "Please enter the price: " << "\n";
		float price;
		std::cin >> price;
		tv.setPrice(price);
		std::cout << "Please enter Diagonal in inches: " << "\n";
		int diagonal;
		std::cin >> diagonal;
		tv.setDiagwnios(diagonal);
		std::cout << "Please enter the Company: " << "\n";
		std::string company;
		std::cin >> company;
		tv.setCompany(company);
		std::cout << "Please enter '1' if 3D view is available or '0' if not: " << "\n";
		bool view3d;
		std::cin >> view3d;
		tv.setView_3d(view3d);
		
		tv.save(outfile);
		tvs.push_back(tv);
		char action;
		std::cout << "Would you like to add another TV? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void readAdmin(std::vector<Admin> &admins) {

	std::ifstream infile;
	infile.open("admins.dat");

	std::string strAdmin;

	while (infile.good()) {
		getline(infile, strAdmin);
		if (strAdmin.length() > 1) {
			admins.push_back(Admin(strAdmin));
		}
	}

	infile.close();
}
void readIndividuals(std::vector<Individuals> &individuals) {

	std::ifstream infile;
	infile.open("individuals.dat");

	std::string strIndividual;

	while (infile.good()) {
		getline(infile, strIndividual);
		if (strIndividual.length() > 1) {
			individuals.push_back(Individuals(strIndividual));
		}
	}

	infile.close();
}
void readCompanies(std::vector<Companies> &companies) {

	std::ifstream infile;
	infile.open("companies.dat");

	std::string strCompany;

	while (infile.good()) {
		getline(infile, strCompany);
		if (strCompany.length() > 1) {
			companies.push_back(Companies(strCompany));
		}
	}

	infile.close();
}
void writeAdmin(std::vector<Admin> &admins) {

	std::ofstream outfile;
	outfile.open("admins.dat", std::ios::app);

	bool read = true;
	while (read) {
		Admin admin = Admin();
		std::cout << "Please enter the prefered username: " << "\n";
		std::string username;
		std::cin >> username;
		//check gia duplicate username
		for(int i=0;i<admins.size();i++){
				
			if(username==admins[i].getUsername()){
				std::cout << "An admin with this username already exists. Please try another username.\n";
				i = -1;
				std::cout << "Please enter the prefered username: " << "\n";
				std::cin >> username;
				continue;
			}
		}
		admin.setUsername(username);
		std::cout << "Please enter the prefered password: " << "\n";
		std::string password;
		std::cin >> password;
		admin.setPassword(password);
		
		admin.save(outfile);
		admins.push_back(admin);
		char action;
		std::cout << "Would you like to add another Admin? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void writeIndividuals(std::vector<Individuals> &individuals,std::vector<Companies> &companies) {

	std::ofstream outfile;
	outfile.open("individuals.dat", std::ios::app);
	bool x;
	bool y;
	
	bool read = true;
	while (read) {
		Individuals individual = Individuals();
		std::cout << "Please enter the prefered username: " << "\n";
		std::string username;
		std::cin >> username;
		//check gia duplicate username
		for(int i=0;i<individuals.size();i++){
				
			if(username==individuals[i].getUsername()){
				std::cout << "An individual with this username already exists. Please try another username.\n";
				i = -1;
				std::cout << "Please enter the prefered username: " << "\n";
				std::cin >> username;
				continue;
			}
		}
		individual.setUsername(username);
		std::cout << "Please enter the prefered password: " << "\n";
		std::string password;
		std::cin >> password;
		individual.setPassword(password);
		std::cout << "Please enter the AFM: " << "\n";
		int afm;
		std::cin >> afm;
		//check gia duplicate afm
		y=false;
		x=true;
		while(x){
		for(int i=0;i<individuals.size();i++){
				
			if(afm==individuals[i].getAfm()){
				std::cout << "An individual with this AFM already exists. Please try another AFM.\n";
				i = -1;
				std::cout << "Please enter the prefered AFM: " << "\n";
				std::cin >> afm;
				continue;
			}
		}
		y=false;
		for(int i=0;i<companies.size();i++){
				
			if(afm==companies[i].getAfm()){
				std::cout << "A company with this AFM already exists. Please try another AFM.\n";
				std::cout << "Please enter the prefered AFM: " << "\n";
				std::cin >> afm;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		x = false;	
		}
		individual.setAfm(afm);
		std::cout << "Please enter the Phone number: " << "\n";
		int phone;
		std::cin >> phone;
		individual.setPhone(phone);
		std::cout << "Please enter the Address: " << "\n";
		std::string address;
		std::cin >> address;
		individual.setAddress(address);
		std::cout << "Please enter the Name: " << "\n";
		std::string name;
		std::cin >> name;
		individual.setName(name);
		std::cout << "Please enter the Surname: " << "\n";
		std::string surname;
		std::cin >> surname;
		individual.setSurname(surname);
		std::cout << "Please enter the ID number: " << "\n";
		std::string id_num;
		std::cin >> id_num;
		individual.setId_num(id_num);
		
		individual.save(outfile);
		individuals.push_back(individual);
		char action;
		std::cout << "Would you like to add another Individual? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void writeCompanies(std::vector<Individuals> &individuals,std::vector<Companies> &companies) {

	std::ofstream outfile;
	outfile.open("companies.dat", std::ios::app);
	bool x;
	bool y;
	bool read = true;
	while (read) {
		Companies company = Companies();
		std::cout << "Please enter your prefered username: " << "\n";
		std::string username;
		std::cin >> username;
		//check gia duplicate username
		for(int i=0;i<companies.size();i++){
				
			if(username==companies[i].getUsername()){
				std::cout << "A company with this username already exists. Please try another username.\n";
				i = -1;
				std::cout << "Please enter the prefered username: " << "\n";
				std::cin >> username;
				continue;
			}
		}
		company.setUsername(username);
		std::cout << "Please enter your prefered password: " << "\n";
		std::string password;
		std::cin >> password;
		company.setPassword(password);
		std::cout << "Please enter the AFM: " << "\n";
		int afm;
		std::cin >> afm;
		//check gia duplicate afm
		y=false;
		x=true;
		while(x){
		for(int i=0;i<individuals.size();i++){
				
			if(afm==individuals[i].getAfm()){
				std::cout << "An individual with this AFM already exists. Please try another AFM.\n";
				i = -1;
				std::cout << "Please enter the prefered AFM: " << "\n";
				std::cin >> afm;
				continue;
			}
		}
		y=false;
		for(int i=0;i<companies.size();i++){
				
			if(afm==companies[i].getAfm()){
				std::cout << "A company with this AFM already exists. Please try another AFM.\n";
				std::cout << "Please enter the prefered AFM: " << "\n";
				std::cin >> afm;
				y=true;
				break;
			}
		}
		if(y){
			continue;
		}
		x = false;	
		}
		company.setAfm(afm);
		std::cout << "Please enter the Phone number: " << "\n";
		int phone;
		std::cin >> phone;
		company.setPhone(phone);
		std::cout << "Please enter the Address: " << "\n";
		std::string address;
		std::cin >> address;
		company.setAddress(address);
		std::cout << "Please enter the Brand: " << "\n";
		std::string brand;
		std::cin >> brand;
		company.setBrand(brand);
		std::cout << "Please enter the Representative's Name: " << "\n";
		std::string name;
		std::cin >> name;
		company.setName(name);
		std::cout << "Please enter the Representative's Surname: " << "\n";
		std::string surname;
		std::cin >> surname;
		company.setSurname(surname);
		std::cout << "Please enter the Discount: " << "\n";
		int discount;
		std::cin >> discount;
		company.setDiscount(discount);
		std::cout << "Please enter the FAX number: " << "\n";
		int fax;
		std::cin >> fax;
		company.setFax(fax);
		
		company.save(outfile);
		companies.push_back(company);
		char action;
		std::cout << "Would you like to add another Company? (y/n): ";
		std::cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void printProducts(std::vector<Product> &products){
	
	for (int i = 0; i < products.size(); i++) {
		std::cout <<"ID:"<< products[i].getID() << " MODEL:" << products[i].getModel() << " MANUFACTURER:" << products[i].getManufacturer() << " PHOTO AVAILABILITY:" << products[i].getPhoto() << " DESCRIPTION:" << products[i].getDescription() <<" Price:"<<products[i].getPrice()<<"\n";
	}
}
void printSmartphones(std::vector<Smartphones> &smartphones){
	
	for (int i = 0; i < smartphones.size(); i++) {
		std::cout <<"ID:"<< smartphones[i].getID() << " MODEL:" << smartphones[i].getModel() << " MANUFACTURER:" << smartphones[i].getManufacturer() << " PHOTO:" << smartphones[i].getPhoto() << " DESCRIPTION:" << smartphones[i].getDescription() <<" Price:"<<smartphones[i].getPrice()<<" Screen Size:"<<smartphones[i].getScreen_size()<<" Battery Duration:"<<smartphones[i].getBattery_duration()<<" 4DVideo:"<<smartphones[i].getVideo_4d()<< "\n";
	}
	std::cout << "\n";
}
void printComputers(std::vector<Computers> &computers){
	
	for (int i = 0; i < computers.size(); i++) {
		std::cout <<"ID:"<< computers[i].getID() << " MODEL:" << computers[i].getModel() << " MANUFACTURER:" << computers[i].getManufacturer() << " PHOTO:" << computers[i].getPhoto() << " DESCRIPTION:" << computers[i].getDescription() <<" Price:"<<computers[i].getPrice()<<" RAM:"<<computers[i].getRam()<<" CPU:"<<computers[i].getCpu()<<" Disk Type:"<<computers[i].getDisk_type()<<" Disk Space:"<<computers[i].getDisk_space()<<" Graphics RAM:"<<computers[i].getGraphics()<< "\n";
	}
	std::cout << "\n";
}
void printTV(std::vector<TV> &tvs){
	
	for (int i = 0; i < tvs.size(); i++) {
		std::cout <<"ID:"<< tvs[i].getID() << " MODEL:" << tvs[i].getModel() << " MANUFACTURER:" << tvs[i].getManufacturer() << " PHOTO:" << tvs[i].getPhoto() << " DESCRIPTION:" << tvs[i].getDescription() <<" Price:"<<tvs[i].getPrice()<<" Diagwnios:"<<tvs[i].getDiagwnios()<<" Company:"<<tvs[i].getCompany()<<" 3D View:"<<tvs[i].getView_3d()<< "\n";
	}
	std::cout << "\n";
}
void deleteProducts(std::vector<Product> &products){
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	
	std::cout << "Please type the ID of the product you want deleted\n";
	std::cin >> id;
	
	outfile.open("products.txt");

	
	for(int i=0;i<products.size();i++){
		if(id==products[i].getID()){
			products.erase(products.begin()+i);
		}
	}
	for(int i=0;i<products.size();i++){
		oss.str("");
		oss.clear();	
		oss << products[i].getID() << "|" << products[i].getModel() << "|" << products[i].getManufacturer() << "|" << products[i].getPhoto() << "|" << products[i].getDescription() << "|" << products[i].getPrice();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "products.dat" );
    std::rename( "products.txt", "products.dat" );
}
void deleteSmartphones(std::vector<Smartphones> &smartphones){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	
	std::cout << "Please type the ID of the Smartphone you want deleted\n";
	std::cin >> id;
	for(int i=0;i<smartphones.size();i++){
		
		if(id==smartphones[i].getID()){
			break;
		}
		
		if(i==(smartphones.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the Smartphone you want deleted\n";
			std::cin >> id;
			continue;
		}
	}
	outfile.open("smartphones.txt");
	
	for(int i=0;i<smartphones.size();i++){
		if(id==smartphones[i].getID()){
			smartphones.erase(smartphones.begin()+i);
		}
	}
	for(int i=0;i<smartphones.size();i++){
		oss.str("");
		oss.clear();	
		oss << smartphones[i].getID() << "|" << smartphones[i].getModel() << "|" << smartphones[i].getManufacturer() << "|" << smartphones[i].getPhoto() << "|" << smartphones[i].getDescription() << "|" << smartphones[i].getPrice() << "|" << smartphones[i].getScreen_size() << "|" << smartphones[i].getBattery_duration() << "|" << smartphones[i].getVideo_4d();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "smartphones.dat" );
    std::rename( "smartphones.txt", "smartphones.dat" );

}
void deleteComputers(std::vector<Computers> &computers){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	
	std::cout << "Please type the ID of the Computer you want deleted\n";
	std::cin >> id;
	for(int i=0;i<computers.size();i++){
		
		if(id==computers[i].getID()){
			break;
		}
		
		if(i==(computers.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the Computer you want deleted\n";
			std::cin >> id;
			continue;
		}
	}
	
	outfile.open("computers.txt");
	
	for(int i=0;i<computers.size();i++){
		if(id==computers[i].getID()){
			computers.erase(computers.begin()+i);
		}
	}
	for(int i=0;i<computers.size();i++){
		oss.str("");
		oss.clear();	
		oss << computers[i].getID() << "|" << computers[i].getModel() << "|" << computers[i].getManufacturer() << "|" << computers[i].getPhoto() << "|" << computers[i].getDescription() << "|" << computers[i].getPrice() << "|" << computers[i].getRam() << "|" << computers[i].getCpu() << "|" << computers[i].getDisk_type() << "|" << computers[i].getDisk_space() << "|" << computers[i].getGraphics();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "computers.dat" );
    std::rename( "computers.txt", "computers.dat" );
	
}
void deleteTV(std::vector<TV> &tvs){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	
	std::cout << "Please type the ID of the TV you want deleted\n";
	std::cin >> id;
	for(int i=0;i<tvs.size();i++){
		
		if(id==tvs[i].getID()){
			break;
		}
		
		if(i==(tvs.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the TV you want deleted\n";
			std::cin >> id;
			continue;
		}
	}
	
	outfile.open("tvs.txt");
	
	for(int i=0;i<tvs.size();i++){
		if(id==tvs[i].getID()){
			tvs.erase(tvs.begin()+i);
		}
	}
	for(int i=0;i<tvs.size();i++){
		oss.str("");
		oss.clear();	
		oss << tvs[i].getID() << "|" << tvs[i].getModel() << "|" << tvs[i].getManufacturer() << "|" << tvs[i].getPhoto() << "|" << tvs[i].getDescription() << "|" << tvs[i].getPrice() << "|" << tvs[i].getDiagwnios() << "|" << tvs[i].getCompany() << "|" << tvs[i].getView_3d();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "tvs.dat" );
    std::rename( "tvs.txt", "tvs.dat" );
	
}
void modifyProducts(std::vector<Product> &products){
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	char select;
	bool x;
	std::string model;
	std::string manufacturer;
	std::string description;
	
	outfile.open("products.txt");
	
	std::cout << "Please type the ID of the product you want to modify\n";
	std::cin >> id;
	//check if id exists
	for(int i=0;i<products.size();i++){
				
		if(id==products[i].getID()){
			break;
		}
		if(i==(products.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the product you want to modify\n";
			std::cin >> id;
			continue;
		}

	}
	
	x = true;
	while(x){

	std::cout << "0: Exit and go back.\n";
	std::cout << "1: Modify model.\n";
	std::cout << "2: Modify manufacturer.\n";
	std::cout << "3: Modify photo availability.\n";
	std::cout << "4: Modify description.\n";
	std::cout << "5: Modify price.\n";
	std::cout << "6: Modify another product.\n";
	std::cin >> select;
	switch(select){
		case '0' :
			x = false;
			break;
		case '1' :
			std::cout << "Please type the new model\n";
			std::cin >> model;
			for(int i=0;i<products.size();i++){
				if(id==products[i].getID()){
					products[i].setModel(model);
				}
			}
			continue;
		case '2' :
			std::cout << "Please type the new manufacturer\n";
			std::cin >> manufacturer;
			for(int i=0;i<products.size();i++){
				if(id==products[i].getID()){
					products[i].setManufacturer(manufacturer);
				}
			}
			continue;
		case '3' :
			std::cout << "Please type '1' if photo available or '0' if not\n";
			bool photo;
			std::cin >> photo;
			for(int i=0;i<products.size();i++){
				if(id==products[i].getID()){
					products[i].setPhoto(photo);
				}
			}
			continue;
		case '4' :
			std::cout << "Please type the new description\n";
			std::cin >> description;
			for(int i=0;i<products.size();i++){
				if(id==products[i].getID()){
					products[i].setDescription(description);
				}
			}
			continue;
		case '5' :
			std::cout << "Please type the new price\n";
			float price;
			std::cin >> price;
			for(int i=0;i<products.size();i++){
				if(id==products[i].getID()){
					products[i].setPrice(price);
				}
			}
			continue;
		case '6' :
			std::cout << "Please type the ID of the product you want to modify\n";
			std::cin >> id;
			for(int i=0;i<products.size();i++){
				
				if(id==products[i].getID()){
					break;
				}
				if(i==(products.size()-1)){
					std::cout << "Product does not exist. Please try another ID.\n";
					i = -1;
					std::cout << "Please type the ID of the product you want to modify\n";
					std::cin >> id;
					continue;
				}

			}
			continue;
		default :
			std::cout << "Invalid selection , Please try again.\n";
			continue;
		}
	}
	for(int i=0;i<products.size();i++){
		oss.str("");
		oss.clear();	
		oss << products[i].getID() << "|" << products[i].getModel() << "|" << products[i].getManufacturer() << "|" << products[i].getPhoto() << "|" << products[i].getDescription() << "|" << products[i].getPrice();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "products.dat" );
    std::rename( "products.txt", "products.dat" );
	
}
void modifySmartphones(std::vector<Smartphones> &smartphones){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	char select;
	bool x;
	std::string model;
	std::string manufacturer;
	std::string description;
	
	outfile.open("smartphones.txt");
	
	std::cout << "Please type the ID of the smartphone you want to modify\n";
	std::cin >> id;
	//check if id exists
	for(int i=0;i<smartphones.size();i++){
				
		if(id==smartphones[i].getID()){
			break;
		}
		if(i==(smartphones.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the smartphone you want to modify\n";
			std::cin >> id;
			continue;
		}

	}
	
	x = true;
	while(x){

	std::cout << "0: Exit and go back.\n";
	std::cout << "1: Modify model.\n";
	std::cout << "2: Modify manufacturer.\n";
	std::cout << "3: Modify photo availability.\n";
	std::cout << "4: Modify description.\n";
	std::cout << "5: Modify price.\n";
	std::cout << "6: Modify screen size.\n";
	std::cout << "7: Modify battery duration.\n";
	std::cout << "8: Modify 4D video availability.\n";
	std::cout << "9: Modify another smartphone.\n";
	std::cin >> select;
	switch(select){
		case '0' :
			x = false;
			break;
		case '1' :
			std::cout << "Please type the new model\n";
			std::cin >> model;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setModel(model);
				}
			}
			continue;
		case '2' :
			std::cout << "Please type the new manufacturer\n";
			std::cin >> manufacturer;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setManufacturer(manufacturer);
				}
			}
			continue;
		case '3' :
			std::cout << "Please type '1' if photo available or '0' if not\n";
			bool photo;
			std::cin >> photo;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setPhoto(photo);
				}
			}
			continue;
		case '4' :
			std::cout << "Please type the new description\n";
			std::cin >> description;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setDescription(description);
				}
			}
			continue;
		case '5' :
			std::cout << "Please type the new price\n";
			float price;
			std::cin >> price;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setPrice(price);
				}
			}
			continue;

		case '6' :
			std::cout << "Please type the new screen size\n";
			float screen_size;
			std::cin >> screen_size;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setScreen_size(screen_size);
				}
			}
			continue;
		case '7' :
			std::cout << "Please type the new battery duraton\n";
			int battery_duration;
			std::cin >> battery_duration;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setBattery_duration(battery_duration);
				}
			}
			continue;
			
		case '8' :
			std::cout << "Please type '1' if 4D video is available or '0' if not\n";
			bool video_4d;
			std::cin >> video_4d;
			for(int i=0;i<smartphones.size();i++){
				if(id==smartphones[i].getID()){
					smartphones[i].setVideo_4d(video_4d);
				}
			}
			continue;
		case '9' :
			std::cout << "Please type the ID of the smartphone you want to modify\n";
			std::cin >> id;
			for(int i=0;i<smartphones.size();i++){
				
				if(id==smartphones[i].getID()){
					break;
				}
				if(i==(smartphones.size()-1)){
					std::cout << "Smartphone does not exist. Please try another ID.\n";
					i = -1;
					std::cout << "Please type the ID of the smartphone you want to modify\n";
					std::cin >> id;
					continue;
				}

			}
			continue;
		default :
			std::cout << "Invalid selection , Please try again.\n";
			continue;
		}
	}
	for(int i=0;i<smartphones.size();i++){
		oss.str("");
		oss.clear();	
		oss << smartphones[i].getID() << "|" << smartphones[i].getModel() << "|" << smartphones[i].getManufacturer() << "|" << smartphones[i].getPhoto() << "|" << smartphones[i].getDescription() << "|" << smartphones[i].getPrice() << "|" << smartphones[i].getScreen_size() << "|" << smartphones[i].getBattery_duration() << "|" << smartphones[i].getVideo_4d();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "smartphones.dat" );
    std::rename( "smartphones.txt", "smartphones.dat" );
	
}
void modifyComputers(std::vector<Computers> &computers){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	int select;
	bool x;
	std::string model;
	std::string manufacturer;
	std::string description;
	std::string disk_type;
	
	outfile.open("computers.txt");
	
	std::cout << "Please type the ID of the computer you want to modify\n";
	std::cin >> id;
	//check if id exists
	for(int i=0;i<computers.size();i++){
				
		if(id==computers[i].getID()){
			break;
		}
		if(i==(computers.size()-1)){
			std::cout << "Computer does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the computer you want to modify\n";
			std::cin >> id;
			continue;
		}

	}
	
	x = true;
	while(x){

	std::cout << "0: Exit and go back.\n";
	std::cout << "1: Modify model.\n";
	std::cout << "2: Modify manufacturer.\n";
	std::cout << "3: Modify photo availability.\n";
	std::cout << "4: Modify description.\n";
	std::cout << "5: Modify price.\n";
	std::cout << "6: Modify ram.\n";
	std::cout << "7: Modify cpu.\n";
	std::cout << "8: Modify disk type.\n";
	std::cout << "9: Modify disk space.\n";
	std::cout << "10: Modify graphics.\n";
	std::cout << "11: Modify another computer.\n";
	std::cin >> select;
	switch(select){
		case 0 :
			x = false;
			break;
		case 1 :
			std::cout << "Please type the new model\n";
			std::cin >> model;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setModel(model);
				}
			}
			continue;
		case 2 :
			std::cout << "Please type the new manufacturer\n";
			std::cin >> manufacturer;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setManufacturer(manufacturer);
				}
			}
			continue;
		case 3 :
			std::cout << "Please type '1' if photo available or '0' if not\n";
			bool photo;
			std::cin >> photo;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setPhoto(photo);
				}
			}
			continue;
		case 4 :
			std::cout << "Please type the new description\n";
			std::cin >> description;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setDescription(description);
				}
			}
			continue;
		case 5 :
			std::cout << "Please type the new price\n";
			float price;
			std::cin >> price;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setPrice(price);
				}
			}
			continue;
		case 6 :
			std::cout << "Please type the new ram in GB\n";
			int ram;
			std::cin >> ram;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setRam(ram);
				}
			}
			continue;
		case 7 :
			std::cout << "Please type the new cpu in GHz\n";
			float cpu;
			std::cin >> cpu;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setCpu(cpu);
				}
			}
			continue;
		case 8 :
			std::cout << "Please type the new disk type\n";
			std::cin >> disk_type;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setDisk_type(disk_type);
				}
			}
			continue;
		case 9 :
			std::cout << "Please type the new disk space in GB\n";
			int disk_space;
			std::cin >> disk_space;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setDisk_space(disk_space);
				}
			}
			continue;
		case 10 :
			std::cout << "Please type the new graphics memory in GB\n";
			int graphics;
			std::cin >> graphics;
			for(int i=0;i<computers.size();i++){
				if(id==computers[i].getID()){
					computers[i].setGraphics(graphics);
				}
			}
			continue;
		case 11 :
			std::cout << "Please type the ID of the computer you want to modify\n";
			std::cin >> id;
			for(int i=0;i<computers.size();i++){
				
				if(id==computers[i].getID()){
					break;
				}
				if(i==(computers.size()-1)){
					std::cout << "Computer does not exist. Please try another ID.\n";
					i = -1;
					std::cout << "Please type the ID of the computer you want to modify\n";
					std::cin >> id;
					continue;
				}

			}
			continue;
		default :
			std::cout << "Invalid selection , Please try again.\n";
			continue;
		}
	}
	for(int i=0;i<computers.size();i++){
		oss.str("");
		oss.clear();	
		oss << computers[i].getID() << "|" << computers[i].getModel() << "|" << computers[i].getManufacturer() << "|" << computers[i].getPhoto() << "|" << computers[i].getDescription() << "|" << computers[i].getPrice() << "|" << computers[i].getRam() << "|" << computers[i].getCpu() << "|" << computers[i].getDisk_type() << "|" << computers[i].getDisk_space() << "|" << computers[i].getGraphics();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "computers.dat" );
    std::rename( "computers.txt", "computers.dat" );
	
}
void modifyTV(std::vector<TV> &tvs){
	
	std::ostringstream oss;
	std::ofstream outfile;
	int id;
	char select;
	bool x;
	std::string model;
	std::string manufacturer;
	std::string description;
	std::string company;
	
	outfile.open("tvs.txt");
	
	std::cout << "Please type the ID of the TV you want to modify\n";
	std::cin >> id;
	//check if id exists
	for(int i=0;i<tvs.size();i++){
				
		if(id==tvs[i].getID()){
			break;
		}
		if(i==(tvs.size()-1)){
			std::cout << "TV does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the TV you want to modify\n";
			std::cin >> id;
			continue;
		}

	}
	
	x = true;
	while(x){

	std::cout << "0: Exit and go back.\n";
	std::cout << "1: Modify model.\n";
	std::cout << "2: Modify manufacturer.\n";
	std::cout << "3: Modify photo availability.\n";
	std::cout << "4: Modify description.\n";
	std::cout << "5: Modify price.\n";
	std::cout << "6: Modify Diagwnios.\n";
	std::cout << "7: Modify Company.\n";
	std::cout << "8: Modify 3D view availability.\n";
	std::cout << "9: Modify another TV.\n";
	std::cin >> select;
	switch(select){
		case '0' :
			x = false;
			break;
		case '1' :
			std::cout << "Please type the new model\n";
			std::cin >> model;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setModel(model);
				}
			}
			continue;
		case '2' :
			std::cout << "Please type the new manufacturer\n";
			std::cin >> manufacturer;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setManufacturer(manufacturer);
				}
			}
			continue;
		case '3' :
			std::cout << "Please type '1' if photo available or '0' if not\n";
			bool photo;
			std::cin >> photo;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setPhoto(photo);
				}
			}
			continue;
		case '4' :
			std::cout << "Please type the new description\n";
			std::cin >> description;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setDescription(description);
				}
			}
			continue;
		case '5' :
			std::cout << "Please type the new price\n";
			float price;
			std::cin >> price;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setPrice(price);
				}
			}
			continue;
		case '6' :
			std::cout << "Please type the new Diagwnios\n";
			int diagwnios;
			std::cin >> diagwnios;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setDiagwnios(diagwnios);
				}
			}
			continue;
		case '7' :
			std::cout << "Please type the new Company\n";
			std::cin >> company;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setCompany(company);
				}
			}
			continue;
		case '8' :
			std::cout << "Please type '1' if 3D view is available or '0' if not\n";
			bool view_3d;
			std::cin >> view_3d;
			for(int i=0;i<tvs.size();i++){
				if(id==tvs[i].getID()){
					tvs[i].setView_3d(view_3d);
				}
			}
			continue;
		case '9' :
			std::cout << "Please type the ID of the TV you want to modify\n";
			std::cin >> id;
			for(int i=0;i<tvs.size();i++){
				
				if(id==tvs[i].getID()){
					break;
				}
				if(i==(tvs.size()-1)){
					std::cout << "TV does not exist. Please try another ID.\n";
					i = -1;
					std::cout << "Please type the ID of the TV you want to modify\n";
					std::cin >> id;
					continue;
				}

			}
			continue;
		default :
			std::cout << "Invalid selection , Please try again.\n";
			continue;
		}
	}
	for(int i=0;i<tvs.size();i++){
		oss.str("");
		oss.clear();	
		oss << tvs[i].getID() << "|" << tvs[i].getModel() << "|" << tvs[i].getManufacturer() << "|" << tvs[i].getPhoto() << "|" << tvs[i].getDescription() << "|" << tvs[i].getPrice() << "|" << tvs[i].getDiagwnios() << "|" << tvs[i].getCompany() << "|" << tvs[i].getView_3d();
		outfile << oss.str() << "\n";
	}
	outfile.close();
    std::remove( "tvs.dat" );
    std::rename( "tvs.txt", "tvs.dat" );
	
}
void addtoProducts(std::vector<Product> &products,std::vector<std::pair<Product,int> > &cart){
	
	std::pair <Product,int> foo;
	
	std::cout << "Please type the ID of the product you want to add to your cart\n";
	int id;
	int x;
	std::cin >> id;
	//check if exists
	for(int i=0;i<products.size();i++){
				
		if(id==products[i].getID()){
			x = i;
			break;
		}
		if(i==(products.size()-1)){
			std::cout << "Product does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the product you want to to add to your cart\n";
			std::cin >> id;
			continue;
		}

	}
	std::cout << "Please type the quantity of the product\n";
	int quantity;
	std::cin >> quantity;
	
	foo = std::make_pair (products[x],quantity);
	cart.push_back(foo);
		
}
void addtoSmartphones(std::vector<Smartphones> &smartphones,std::vector<std::pair<Product,int> > &cart){
	
	std::pair <Product,int> foo;
	
	std::cout << "Please type the ID of the smartphone you want to add to your cart\n";
	int id;
	int x;
	std::cin >> id;
	//check if exists
	for(int i=0;i<smartphones.size();i++){
				
		if(id==smartphones[i].getID()){
			x = i;
			break;
		}
		if(i==(smartphones.size()-1)){
			std::cout << "Smartphone does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the smartphone you want to to add to your cart\n";
			std::cin >> id;
			continue;
		}

	}
	std::cout << "Please type the quantity of the smartphone\n";
	int quantity;
	std::cin >> quantity;
	
	foo = std::make_pair (smartphones[x],quantity);
	cart.push_back(foo);
	
}
void addtoComputers(std::vector<Computers> &computers,std::vector<std::pair<Product,int> > &cart){
	
	std::pair <Product,int> foo;
	
	std::cout << "Please type the ID of the computer you want to add to your cart\n";
	int id;
	int x;
	std::cin >> id;
	//check if exists
	for(int i=0;i<computers.size();i++){
				
		if(id==computers[i].getID()){
			x = i;
			break;
		}
		if(i==(computers.size()-1)){
			std::cout << "Computer does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the computer you want to to add to your cart\n";
			std::cin >> id;
			continue;
		}

	}
	std::cout << "Please type the quantity of the computer\n";
	int quantity;
	std::cin >> quantity;
	
	foo = std::make_pair (computers[x],quantity);
	cart.push_back(foo);
	
}
void addtoTV(std::vector<TV> &tvs,std::vector<std::pair<Product,int> > &cart){
	
	std::pair <Product,int> foo;
	
	std::cout << "Please type the ID of the TV you want to add to your cart\n";
	int id;
	int x;
	std::cin >> id;
	//check if exists
	for(int i=0;i<tvs.size();i++){
				
		if(id==tvs[i].getID()){
			x = i;
			break;
		}
		if(i==(tvs.size()-1)){
			std::cout << "TV does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the TV you want to to add to your cart\n";
			std::cin >> id;
			continue;
		}

	}
	std::cout << "Please type the quantity of the TV\n";
	int quantity;
	std::cin >> quantity;
	
	foo = std::make_pair (tvs[x],quantity);
	cart.push_back(foo);
	
}
void printCart(std::vector<std::pair<Product,int> > &cart){
	
	for(int i=0;i<cart.size();i++){
		
		std::cout <<"ID:"<< cart[i].first.getID() << " MODEL:" << cart[i].first.getModel() << " MANUFACTURER:" << cart[i].first.getManufacturer() << " PHOTO:" << cart[i].first.getPhoto() << " DESCRIPTION:" << cart[i].first.getDescription() <<" Price:"<<cart[i].first.getPrice()<<" QUANTITY:"<<cart[i].second<<"\n";
		
	}
	std::cout << "\n";	
}
void deletefromCart(std::vector<std::pair<Product,int> > &cart){
	
	std::cout << "Please type the ID of the product you want deleted from your cart\n";
	int id;
	std::cin >> id;
	//check if id exists
	if(cart.size()>0){
	for(int i=0;i<cart.size();i++){
				
		if(id==cart[i].first.getID()){
			cart.erase(cart.begin()+i);
			break;
			}
		if(i==(cart.size()-1)){
			std::cout << "Product does not exist in your cart. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the product you want deleted from your cart\n";
			std::cin >> id;
			continue;
			}

		}
	}
	else{
		std::cout << "Your shopping cart is empty\n";
	}
	
}
void makeOrder(int afm,std::vector<std::pair<Product,int> > &cart,std::vector<Orders> &orders){
		
	std::cout << "Please enter Order ID: " << "\n";
	int id;
	std::cin >> id;
	for (int i=0;i<orders.size();i++){
		if(id==orders[i].getOrder_id()){
			i=-1;
			std::cout << "This order ID already exists,Please try another ID\n";
			std::cin >> id;
			continue;
		}
	}
	float cost;
	float total_cost = 0;
	for(int i=0;i<cart.size();i++){
		cost = cart[i].first.getPrice() * cart[i].second;
		total_cost = total_cost + cost;
	}
	Orders order = Orders(id,afm,cart,total_cost,"Ekremei");
	orders.push_back(order);
	
}
void makeDorder(int discount,int afm,std::vector<std::pair<Product,int> > &cart,std::vector<Orders> &orders){
		
	std::cout << "Please enter Order ID: " << "\n";
	int id;
	std::cin >> id;
	float cost;
	float total_cost = 0;
	for(int i=0;i<cart.size();i++){
		cost = cart[i].first.getPrice() * cart[i].second;
		total_cost = total_cost + cost;
	}
	total_cost = total_cost - (discount*total_cost)/100.0;
	Orders order = Orders(id,afm,cart,total_cost,"Ekremei");
	orders.push_back(order);
	
}
void modifyOrderStatus(std::vector<Orders> &orders){
	
	std::string order_status;
	std::cout << "Please type the ID of the order: " << "\n";
	int id;
	std::cin >> id;
	//check if id exists
	for(int i=0;i<orders.size();i++){
				
		if(id==orders[i].getOrder_id()){
			std::cout << "Please type the new order status: " << "\n";
			std::cin >> order_status;
			orders[i].setOrder_status(order_status);
			break;
		}
		if(i==(orders.size()-1)){
			std::cout << "Order ID does not exist. Please try another ID.\n";
			i = -1;
			std::cout << "Please type the ID of the order\n";
			std::cin >> id;
			continue;
		}

	}
}
void printOrders(std::vector<Orders> &orders){
	
	std::cout << "Please type customer AFM: " << "\n";
	int afm;
	std::cin >> afm;
	for(int i =0;i<orders.size();i++){
		if(afm==orders[i].getCustomer_afm()){
			break;	
		}
		if(i==(orders.size()-1)){
			std::cout  << "An order with this customer AFM does not exist.Please try another AFM\n";
			i = -1;
			std::cout << "Please type customer AFM: " << "\n";
			std::cin >> afm;
			continue;
		}
	}
	
	for (int i = 0; i < orders.size(); i++) {
		if(afm==orders[i].getCustomer_afm()){
			std::cout << std::string(50, '\n');
			for(int j = 0;j < orders[i].getCart().size();j++){
				std::cout <<"Order ID:"<< orders[i].getOrder_id() << " Customer AFM:" << orders[i].getCustomer_afm() << " Product ID:" << orders[i].getCart()[j].first.getID() << " Model:" << orders[i].getCart()[j].first.getModel() << " Manufacturer:" << orders[i].getCart()[j].first.getManufacturer() <<" Quantity:" <<orders[i].getCart()[j].second << " Total Price:" << orders[i].getOrder_cost() << " Order Status:"<<orders[i].getOrder_status()<<"\n";
			}
			std::cout << "\n";
		}
	}
}
void printIndividuals(std::vector<Individuals> &individuals){
	if(individuals.size()>0){
		for(int i=0;i<individuals.size();i++){
			std::cout << "Name:" << individuals[i].getName() << " Surname:" << individuals[i].getSurname() << " ID NUMBER:" << individuals[i].getId_num() << " AFM:" << individuals[i].getAfm() << " Phone:" << individuals[i].getPhone() << " Address:" << individuals[i].getAddress() << "\n";
		
		}
		std::cout << "\n";
	}
	else{
		std::cout << "------There are no customers from this category------\n\n";
	}
	
}
void printCompanies(std::vector<Companies> &companies){
	if(companies.size()>0){
		for(int i=0;i<companies.size();i++){
			std::cout << "Name:" << companies[i].getRep_name() << " Surname:" << companies[i].getRep_surname() << " Brand:" << companies[i].getBrand() << " Discount %:" << companies[i].getDiscount() << " FAX:" << companies[i].getFax() <<" AFM:"<<companies[i].getAfm() << " Phone:" << companies[i].getPhone() << " Address:" << companies[i].getAddress() << "\n";
		
		}
		std::cout << "\n";
	}
	else{
		std::cout << "------The are no customers from this category------\n\n";
	}
}
void printOrderStatus(int afm,std::vector<Orders> &orders){
	
	bool x;
	x = true;
	
	for (int i = 0; i < orders.size(); i++) {
		if(afm==orders[i].getCustomer_afm()){
			for(int j = 0;j < orders[i].getCart().size();j++){
				std::cout <<"Order ID:"<< orders[i].getOrder_id()<< " Product ID:" << orders[i].getCart()[j].first.getID() << " Model:" << orders[i].getCart()[j].first.getModel() << " Manufacturer:" << orders[i].getCart()[j].first.getManufacturer() <<" Quantity:" <<orders[i].getCart()[j].second << " Total Price:" << orders[i].getOrder_cost() << " Order Status:"<<orders[i].getOrder_status()<<"\n";
			}
			std::cout << "\n";
			x = false;
		}
	}
	if(x){
		std::cout << "--------You have no orders placed--------\n\n";
	}
	
}

