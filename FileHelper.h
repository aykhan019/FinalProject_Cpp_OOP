#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "Classes.h"
using namespace std;

void ExceptionWriteToFile(const string& filename, Exception text) {
	ofstream fout(filename, ios::app);
	if (fout.is_open()) {
		fout << "\n";
		fout << "ERROR";
		fout << "\n";
		fout << "Date : ";
		fout << text.GetDate();
		fout << "\n";
		fout << "Source : ";
		fout << text.GetSource();
		fout << "\n";
		fout << "Line : ";
		fout << text.GetLine();
		fout << "\n";
		fout << "Message : ";
		fout << text.GetText();
		fout << "\n";
	}
	else {
		cout << filename << " does not exists" << endl;
	}
	fout.close();
}

void OrderWriteToFile(const string& filename, Table* table, const bool& orderAccepted) {
	ofstream fout(filename, ios::app);
	if (fout.is_open()) {
		fout << "\n========================================" << endl;
		if (orderAccepted)
		{
			fout << "Table ";
			fout << table->GetTableNo();
			fout << "\'s orders have been accepted" << endl;
		}
		else
		{
			fout << "Table ";
			fout << table->GetTableNo();
			fout << "\'s orders have not been accepted" << endl;
		}
		fout << "\nORDER DETAILS" << endl;
		fout << "Table No : ";
		fout << table->GetTableNo() << endl;
		int order_count = table->GetOrderCount();
		Order** orders = table->GetOrders();
		double totalPrice = 0;
		fout << "Meals : " << endl;
		for (int x = 0; x < order_count; x++)
		{
			Meal* meal = orders[x]->GetMeal();
			string meal_name = meal->GetName();
			int meal_count = orders[x]->GetMealCount();
			fout << x + 1 << ") ";
			fout << meal_count;
			fout << " ";
			fout << meal_name << endl;
			totalPrice += meal->CalculatePriceOfMeal() * meal_count;
		}
		fout << "Total price : ";
		fout << totalPrice;
		fout << "$" << endl;
		fout << "========================================" << endl;
	}
	else {
		cout << filename << " does not exists" << endl;
	}
	fout.close();
}

