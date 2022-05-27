#pragma once
#include <iostream>
#include <assert.h>
#include <fcntl.h>
#include <io.h>
#include "Color.h"
#include "CursorFunctions.h"
using namespace std;

class Exception
{
protected:
	string text;
	string source; // file
	int line;
	string date;
public:
	Exception(string text, string source, int line, string date)
		:text(text), source(source), line(line), date(date) {}

	string GetText() const
	{
		return text;
	}
	string GetSource() const
	{
		return source;
	}
	int GetLine() const
	{
		return line;
	}
	string GetDate() const
	{
		return date;
	}

	virtual void PrintMessage() const
	{
		cout << "========= ERROR INFO ========= " << endl;
		cout << "Error Content : " << text << endl;
		cout << "Source : " << source << endl;
		cout << "Line Number : " << line << endl;
		cout << "Date : " << date << endl;
	}
};

class DatabaseException : public Exception
{
public:
	DatabaseException(const string& text, const string& source, const int& line, const string& date)
		: Exception(text, source, line, date) {}

	void PrintMessage() const override
	{
		system("color 4");
		cout << "\nError type : " << "DatabaseException" << endl;
		Exception::PrintMessage();
	}
};

class InvalidArgumentException : public Exception
{
public:
	InvalidArgumentException(const string& text, const string& source, const int& line, const string& date)
		:Exception(text, source, line, date) {}

	void PrintMessage() const override
	{
		system("color 4");
		cout << "\nError type : InvalidArgumentException" << endl;
		Exception::PrintMessage();
	}
};

class Ingredient {
	string name;
	double fats;
	double protein;
	double carbohydrates;
	int kcal;
	double price;
public:
#pragma region Constructors
	Ingredient()
	{
		name = "";
		fats = 0;
		protein = 0;
		carbohydrates = 0;
		kcal = 0;
	}
	Ingredient(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price)
	{
		SetName(name);
		SetFats(fats);
		SetProtein(protein);
		SetCarbohydrates(carbohydrates);
		SetKcal(kcal);
		SetPrice(price);
	}
#pragma endregion

#pragma region Getters
	string GetName() const
	{
		return name;
	}
	double GetFats() const
	{
		return fats;
	}
	double GetProtein() const
	{
		return protein;
	}
	double GetCarbohydrates() const
	{
		return carbohydrates;
	}
	int GetKcal() const
	{
		return kcal;
	}
	double GetPrice() const
	{
		return price;
	}
#pragma endregion

#pragma region Setters
	void SetName(const string& name)
	{
		assert(!name.empty() && "Name should be filled!");
		this->name = name;
	}
	void SetFats(const double& fats)
	{
		assert(fats>= 0 && "Fats cannot be less than 0!");
		this->fats = fats;
	}
	void SetProtein(const double& protein)
	{
		assert(protein>= 0 && "Protein cannot be less than 0!");
		this->protein = protein;
	}
	void SetCarbohydrates(const double& carbohydrates)
	{
		assert(carbohydrates>= 0 && "Carbohydrates cannot be less than 0!");
		this->carbohydrates = carbohydrates;
	}
	void SetKcal(const double& kcal)
	{
		assert(kcal >= 0 && "Kcal cannot be less than 0!");
		this->kcal = kcal;
	}
	void SetPrice(const double& price)
	{
		assert(price > 0 && "Price cannot be less than 0!");
		this->price = price;
	}
#pragma endregion

#pragma region Destructor
	virtual ~Ingredient() = 0
	{

	}
#pragma endregion
};

#pragma region Ingredients

class Bread : public Ingredient
{
public:
	Bread() = delete;
	Bread(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Pasta: public Ingredient
{
public:
	Pasta() = delete;
	Pasta(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Salt: public Ingredient
{
public:
	Salt() = delete;
	Salt(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Seasoning: public Ingredient
{
public:
	Seasoning() = delete;
	Seasoning(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Bean : public Ingredient
{
public:
	Bean() = delete;
	Bean(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Rice : public Ingredient
{
public:
	Rice() = delete;
	Rice(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Mushroom : public Ingredient
{
public:
	Mushroom() = delete;
	Mushroom(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Meat : public Ingredient
{
public:
	Meat() = delete;
	Meat(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Spices :public Ingredient
{
public:
	Spices() = delete;
	Spices(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Broccoli : public Ingredient
{
public:
	Broccoli() = delete;
	Broccoli(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Cheese :public Ingredient
{
public:
	Cheese() = delete;
	Cheese(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Tomatoes :public Ingredient
{
public:
	Tomatoes() = delete;
	Tomatoes(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{
		
	}
};

class Eggs : public Ingredient
{
public:
	Eggs() = delete;
	Eggs(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class FreshHerbs :public Ingredient
{
public:
	FreshHerbs() = delete;
	FreshHerbs(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Milk : public Ingredient
{
public:
	Milk() = delete;
	Milk(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Orange : public Ingredient
{
public:
	Orange() = delete;
	Orange(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Pear : public Ingredient
{
public:
	Pear() = delete;
	Pear(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Potato : public Ingredient
{
public:
	Potato() = delete;
	Potato(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Onion: public Ingredient
{
public:
	Onion() = delete;
	Onion(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Oil : public Ingredient
{
public:
	Oil() = delete;
	Oil(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Flour : public Ingredient
{
public:
	Flour() = delete;
	Flour(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Veggies : public Ingredient
{
public:
	Veggies() = delete;
	Veggies(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Butter: public Ingredient
{
public:
	Butter() = delete;
	Butter(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Toast : public Ingredient
{
public:
	Toast() = delete;
	Toast(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Cinnamon: public Ingredient
{
public:
	Cinnamon() = delete;
	Cinnamon(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Sugar: public Ingredient
{
public:
	Sugar() = delete;
	Sugar(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

class Garlic : public Ingredient
{
public:
	Garlic() = delete;
	Garlic(const string& name, const double& fats, const double& protein, const double& carbohydrates, const int& kcal, const double& price) :
		Ingredient(name, fats, protein, carbohydrates, kcal, price)
	{

	}
};

#pragma endregion

struct RecipeItem {
private:
	Ingredient* ingredient;
	int amount = 0;
public:
#pragma region Constructors
	RecipeItem() = delete;
	RecipeItem(Ingredient* ingredient, const int& amount)
	{
		SetIngredient(ingredient);
		SetAmount(amount);
	}
#pragma endregion

#pragma region Setters
	void SetIngredient(Ingredient* ingredient)
	{
		this->ingredient = ingredient;
	}
	void SetAmount(const int& amount)
	{
		assert(amount  >= 0 && "Amount cannot be less than 0!");
		this->amount = amount;
	}
#pragma endregion

#pragma region Getter
	int GetAmount() const
	{
		return amount;
	}
	Ingredient* GetIngredient() const
	{
		return ingredient;
	}
#pragma endregion
#pragma region Methods
	void Show()
	{
		if (ingredient->GetName() == "Salt")
			cout << " " << GetAmount() << " Spoon " << ingredient->GetName() << endl;
		else
			cout << " " << GetAmount() << " " << ingredient->GetName() << endl;
	}
#pragma endregion

};

class Meal {
	RecipeItem** items;
	int count;
	string name;
public:
#pragma region Constructors
	Meal() = delete;

	Meal(RecipeItem** items, const int& count, const string& name)
	{
		SetItems(items);
		SetItemCount(count);
		SetName(name);
	}
#pragma endregion

#pragma region Setters
	void SetItems(RecipeItem** items)
	{
		this->items = items;
	}
	void SetItemCount(const int& count)
	{
		assert(count  >= 0 && "Item count cannot be less than 0!");
		this->count = count;
	}
	void SetName(const string& name)
	{
		assert(!name.empty() && "Dish name should be filled!");
		this->name = name;
	}
#pragma endregion

#pragma region Getters
	string GetName() const
	{
		return name;
	}
	RecipeItem** GetItems() const
	{
		return items;
	}
	int GetIngredientCount() const
	{
		return count;
	}
#pragma endregion

#pragma region Methods
	bool MealHasThisIngredient(string ingredient_name) const
	{
		for (int x = 0; x < count; x++)
		{
			if (items[x]->GetIngredient()->GetName() == ingredient_name)
			{
				return true;
			}
		}
		return false;
	}

	int GetIngredientIndex(const string& ingredinet_name) const
	{
		for (int x = 0; x < count; x++)
		{
			if (items[x]->GetIngredient()->GetName() == ingredinet_name)
			{
				return x;
			}
		}
	}

	void AddIngredient(RecipeItem* item)
	{
		string name = item->GetIngredient()->GetName();
		if (MealHasThisIngredient(name))
		{
			int index = GetIngredientIndex(name);
			this->items[index]->SetAmount(this->items[index]->GetAmount() + item->GetAmount());
		}
		else
		{
			RecipeItem** newitems = new RecipeItem * [count + 1]{};
			for (int x = 0; x < count; x++)
			{
				newitems[x] = items[x];
			}
			newitems[count] = item;
			if (count != 0)
			{
				delete[]items;
			}
			items = newitems;
			count++;
			newitems = nullptr;
		}
	}

	virtual void Taste()
	{
		cout << "I do not know what is this ? " << endl;
	}

	virtual void Show()
	{
		system("cls");
		cout << " ========= Recipe =========" << endl;
		for (int x = 0; x < count; x++)
		{
			items[x]->Show();
		}
	}

	double GetTotalKcal() const
	{
		double totalKcal = 0;
		RecipeItem** items = GetItems();
		int count = GetIngredientCount();
		for (int x = 0; x < count; x++)
		{
			totalKcal += items[x]->GetIngredient()->GetKcal();
		}
		return totalKcal;
	}

	double GetTotalCarbohydrates() const
	{
		double totalCarbohydrates = 0;
		RecipeItem** items = GetItems();
		int count = GetIngredientCount();
		for (int x = 0; x < count; x++)
		{
			totalCarbohydrates += items[x]->GetIngredient()->GetCarbohydrates();
		}
		return totalCarbohydrates;
	}

	double GetTotalFats() const
	{
		double totalFats = 0;
		RecipeItem** items = GetItems(); 
		int count = GetIngredientCount();
		for (int x = 0; x < count; x++)
		{
			totalFats += items[x]->GetIngredient()->GetFats();
		}
		return totalFats;
	}

	double GetTotalProtein() const
	{
		double totalProtein = 0;
		RecipeItem** items = GetItems();
		int count = GetIngredientCount();
		for (int x = 0; x < count; x++)
		{
			totalProtein += items[x]->GetIngredient()->GetProtein();
		}
		return totalProtein;
	}

	void PrintFeaturesOfMeal() const
	{
		for (int x = 0; x < count; x++)
		{
			cout << "  " << x + 1 << ")";
			items[x]->Show();
		}
		int totalKcal = GetTotalKcal();
		cout << "\n Total Kcal : " << totalKcal << endl;
		int totalCarbohydrates = GetTotalCarbohydrates();
		cout << " Total Carbohydrates : " << totalCarbohydrates << endl;
		int totalFats = GetTotalFats();
		cout << " Total Fats : " << totalFats << endl;
		int totalProtein = GetTotalProtein();
		cout << " Total Protein : " << totalProtein << endl;
		double totalPriceOfMeal = CalculatePriceOfMeal();
		cout << "\n Total Price of the Meal : " << totalPriceOfMeal << "$" << endl;
	}

#pragma endregion

#pragma region Methods
	bool HasEnoughIngredients(RecipeItem** items)
	{

	}
	double CalculatePriceOfMeal() const
	{
		double totalPrice = 0;
		for (int x = 0; x < count; x++)
		{
			totalPrice += items[x]->GetIngredient()->GetPrice() * items[x]->GetAmount();
		}
		return totalPrice;
	}
#pragma endregion

#pragma region Destructor
	// Pure virtual destructor
	virtual ~Meal() = 0
	{

	}
#pragma endregion
};

#pragma region Meals

class PastaPrimavera :public Meal
{
public:
	PastaPrimavera() = delete;
	PastaPrimavera(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Pasta Primavera" << endl;
		PrintFeaturesOfMeal();
	}
};

class PastaPomodoro :public Meal
{
public:
	PastaPomodoro() = delete;
	PastaPomodoro(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Pasta Pomodoro" << endl;
		PrintFeaturesOfMeal();
	}
};

class RiceAndBeans :public Meal
{
public:
	RiceAndBeans() = delete;
	RiceAndBeans(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Rice And Beans" << endl;
		PrintFeaturesOfMeal();
	}
};

class GrilledCheese :public Meal
{
public:
	GrilledCheese() = delete;
	GrilledCheese(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Grilled Cheese " << endl;
		PrintFeaturesOfMeal();
	}
};

class GarlicButterBroccoli : public Meal
{
public:
	GarlicButterBroccoli() = delete;
	GarlicButterBroccoli(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Garlic - Butter Broccoli" << endl; 
		PrintFeaturesOfMeal();
	}
};

class Chili: public Meal
{
public:
	Chili() = delete;
	Chili(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Chili"<< endl;
		PrintFeaturesOfMeal();
	}
};

class NoodleSoup : public Meal
{
public:
	NoodleSoup() = delete;
	NoodleSoup(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Noodle Soup" << endl;
		PrintFeaturesOfMeal();
	}
};

class FriedRice : public Meal
{
public:
	FriedRice() = delete;
	FriedRice(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Fried Rice" << endl;
		PrintFeaturesOfMeal();
	}
};

class Risotto: public Meal
{
public:
	Risotto() = delete;
	Risotto(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Risotto" << endl;
		PrintFeaturesOfMeal();
	}
};

class EggsAndToast : public Meal
{
public:
	EggsAndToast() = delete;
	EggsAndToast(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Eggs And Toast" << endl;
		PrintFeaturesOfMeal();
	}
};

class FrenchToast : public Meal
{
public:
	FrenchToast() = delete;
	FrenchToast(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of French Toast" << endl;
		PrintFeaturesOfMeal();
	}
};

class VegetarianOmelette : public Meal
{
public:
	VegetarianOmelette() = delete;
	VegetarianOmelette(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Vegetarian Omelette" << endl;
		PrintFeaturesOfMeal();
	}
};

class Pancakes : public Meal
{
public:
	Pancakes() = delete;
	Pancakes(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Pancakes"<< endl;
		PrintFeaturesOfMeal();
	}
};

class Shakshuka: public Meal
{
public:
	Shakshuka() = delete;
	Shakshuka(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Shakshuka" << endl;
		PrintFeaturesOfMeal();
	}
};

class CinnamonRolls : public Meal
{
public:
	CinnamonRolls() = delete;
	CinnamonRolls(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Cinnamon Rolls" << endl;
		PrintFeaturesOfMeal();
	}
};

class RicePudding : public Meal
{
public:
	RicePudding() = delete;
	RicePudding(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Rice Pudding" << endl;
		PrintFeaturesOfMeal();
	}
};

class VanillaPudding : public Meal
{
public:
	VanillaPudding() = delete;
	VanillaPudding(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Vanilla Pudding" << endl;
		PrintFeaturesOfMeal();
	}
};

class VanillaCustardPie : public Meal
{
public:
	VanillaCustardPie() = delete;
	VanillaCustardPie(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Vanilla Custard Pie" << endl;
		PrintFeaturesOfMeal();
	}
};

class BreadPudding : public Meal
{
public:
	BreadPudding() = delete;
	BreadPudding(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n Recipe of Bread Pudding" << endl;
		PrintFeaturesOfMeal();
	}
};

class Doner : public Meal
{
public:
	Doner() = delete;
	Doner(RecipeItem** items, const int& count, const string& name)
		: Meal(items, count, name)
	{

	}

	virtual void Show() override final
	{
		system("cls");
		cout << "\n ========= Recipe of Doner" << endl;
		PrintFeaturesOfMeal();
	}
};

#pragma endregion

class Order
{
private:
	int tableNo;
	Meal* meal;
	int meal_count;
public:
#pragma region Constructor
	Order() = default;
	Order(const int& tableNo, Meal*& meal, const int& meal_count)
	{
		SetTableNo(tableNo);
		SetMealCount(meal_count);
		SetMeals(meal);
	}
#pragma endregion

#pragma region Getters
	int GetTableNo() const
	{
		return tableNo;
	}
	Meal* GetMeal() const
	{
		return meal;
	}
	int GetMealCount() const
	{
		return meal_count;
	}
#pragma endregion

#pragma region Setters
	void SetTableNo(const int& tableNo)
	{
		this->tableNo = tableNo;
	}
	void SetMeals(Meal*& meal)
	{
		this->meal = meal;
	}
	void SetMealCount(const int& meal_count)
	{
		this->meal_count = meal_count;
	}
#pragma endregion

#pragma region Methods
	void ShowOrder()
	{
		SetColor(WHITE);
		cout << "  Order : ";
		int count = GetMealCount();
		cout << " " << count << " " << meal->GetName() << endl;
	}
#pragma endregion
};

class Table
{
private:
	int no;
	bool hasClient;
	Order** orders;
	int order_count;
	string messageFromKitchen;
public:
	static int NO;

#pragma region Constructors
	Table() : no(NO), hasClient(false), orders(nullptr), order_count(0) {}

	Table(const bool& hasClient, Order** orders, const int& order_count)
	{
		SetTableNo();
		SetHasClient(hasClient);
		SetOrderCount(order_count);
		SetOrders(orders);
	}
#pragma endregion

#pragma region Setters
	void SetTableNo()
	{
		this->no = NO;
		NO++;
	}
	void SetHasClient(const bool& hasClient)
	{
		this->hasClient = hasClient;
	}
	void SetOrders(Order** orders)
	{
		this->orders = orders;
	}
	void SetOrderCount(const int& order_count)
	{
		assert(order_count >= 0 && "Order count cannot be less than 0!");
		this->order_count = order_count;
	}
#pragma endregion

#pragma region Getters
	int GetTableNo() const
	{
		return no;
	}
	bool GetHasClient() const
	{
		return hasClient;
	}
	Order** GetOrders() const
	{
		return orders;
	}
	int GetOrderCount() const
	{
		return order_count;
	}
#pragma endregion

#pragma region Methods 
	void AddOrder(const Order& neworder)
	{
		Order** newOrders = new Order * [order_count + 1]{};
		for (int x = 0; x < order_count; x++)
		{
			newOrders[x] = orders[x];
		}
		if (order_count != 0)
		{
			delete[]orders;
		}
		newOrders[order_count] = new Order{ neworder };
		orders = newOrders;
		order_count++;
		newOrders = nullptr;
	}

	int GetOrderIndexByTableNo(const int& tableNo)
	{
		for (int x = 0; x < order_count; x++)
		{
			if (orders[x]->GetTableNo() == tableNo)
			{
				return x;
			}
		}
		throw InvalidArgumentException("There is no order in table", __FILE__, __LINE__, __DATE__);
	}

	void DeleteOrderByTableNo(const int& tableNo)
	{
		if (order_count > 0)
		{
			int index = GetOrderIndexByTableNo(tableNo);
			Order** newOrders = new Order * [order_count - 1]{};
			for (int x = 0; x < index; x++)
			{
				newOrders[x] = orders[x];
			}
			for (int y = index + 1; y < order_count + 1; y++)
			{
				newOrders[y - 1] = orders[y];
			}
			delete[]orders;
			orders = newOrders;
			order_count--;
			newOrders = nullptr;
		}
		else
		{
			throw InvalidArgumentException("There is no order to delete", __FILE__, __LINE__, __DATE__);
		}
	}
#pragma endregion

#pragma region Destructor
	~Table()
	{
		for (int x = 0; x < order_count; x++)
		{
			delete orders[x];
		}
		delete[]orders;
	}
#pragma endregion
};

int Table::NO = 1;

class Stock
{
private:
	RecipeItem** ingredients;
	int ingredient_count = 0;
public:
	Stock() = delete;
	Stock(RecipeItem** ingredients, const int& ingredient_count)
	{
		SetIngredients(ingredients);
		SetIngredientCount(ingredient_count);
	}

	void SetIngredientCount(const int& ingredient_count)
	{
		assert(ingredient_count >= 0 && "Ingredient count cannot be less than 0!");
		this->ingredient_count = ingredient_count;
	}

	void SetIngredients(RecipeItem** ingredients)
	{
		this->ingredients = ingredients;
	}

	RecipeItem** GetIngredients() const
	{
		return ingredients;
	}

	int GetIngredientCount() const
	{
		return ingredient_count;
	}

	void ShowAllIngredients() const
	{
		cout << " ================================= ALL INGREDIENTS ================================= " << endl;
		for (int x = 0; x < ingredient_count; x++)
		{
			cout << " ";
			ingredients[x]->Show();
		}
	}

	void AddIngredient(RecipeItem* new_ingredient)
	{
		RecipeItem** new_ingredients = new RecipeItem * [ingredient_count + 1]{};
		for (int x = 0; x < ingredient_count; x++)
		{
			new_ingredients[x] = ingredients[x];
		}
		new_ingredients[ingredient_count] = new_ingredient;
		if (ingredient_count != 0)
		{
			delete[]ingredients;
		}
		ingredients = new_ingredients;
		ingredient_count++;
		new_ingredients = nullptr;
	}
	
	int GetIngredientIndexByName(const string& ingredient_name) const throw (InvalidArgumentException)
	{
		for (int x = 0; x < ingredient_count; x++)
		{
			if (ingredients[x]->GetIngredient()->GetName() == ingredient_name)
			{
				return x;
			}
		}
		throw InvalidArgumentException("Ingredient with this name does not exist in the stock", __FILE__, __LINE__, __DATE__);
	}

	void DeleteIngredientByName(const string& ingredient_name)
	{
		int index = GetIngredientIndexByName(ingredient_name);
		if (index) // if ingredient exist in the stock
		{
			RecipeItem** new_ingredients = new RecipeItem * [ingredient_count - 1]{};
			for (int x = 0; x < index; x++)
			{
				new_ingredients[x] = ingredients[x];
			}
			for (int y = index + 1; y < ingredient_count + 1; y++)
			{
				new_ingredients[y - 1] = ingredients[y];
			}
			if (ingredient_count != 0)
			{
				delete[]ingredients;
			}
			ingredients = new_ingredients;
			ingredient_count--;
			new_ingredients = nullptr;
		}
	}

	void IncreaseIngredientAmountByName(const string& ingredient_name, int increase_count)
	{
		int index = GetIngredientIndexByName(ingredient_name);
		if (index) // if ingredient exist in the stock
		{
			int amount = ingredients[index]->GetAmount();
			ingredients[index]->SetAmount(amount + increase_count);
		}
	}

	void DecreaseIngredientAmountByName(const string& ingredient_name, int decrease_count)
	{
		int index = GetIngredientIndexByName(ingredient_name);
		if (index) // if ingredient exist in the stock
		{
			int amount = ingredients[index]->GetAmount();
			ingredients[index]->SetAmount(amount - decrease_count);
		}
	}

	bool ThereIsEnoughIngredient(const string& ingredient_name, int decrease_count) throw (InvalidArgumentException)
	{
		int index = GetIngredientIndexByName(ingredient_name);
		if (index) // if ingredient exist in the stock
		{
			int amount = ingredients[index]->GetAmount();
			if (amount - decrease_count < 0)
				throw InvalidArgumentException("There is not enough " + ingredient_name + " in the stock", __FILE__, __LINE__, __DATE__);
		}
		else
			return true;
	}

	bool HasEnoughIngredientForMeal(const Meal& meal) const
	{
		int ing_count = meal.GetIngredientCount();
		RecipeItem** items = meal.GetItems(); // ingredinets
		for (int x = 0; x < ing_count; x++)
		{
			int index = GetIngredientIndexByName(items[x]->GetIngredient()->GetName());
			if (ingredients[index]->GetAmount() - items[x]->GetAmount() < 0)
			{
				return false;
			}
		}
		return true;
	}

	void ReduceIngredientsByTable(Table* table)
	{
		//orders[x]->GetMealCount()
		Order** orders = table->GetOrders();
		int order_count = table->GetOrderCount();
		for (int x = 0; x < order_count; x++)
		{
			int length = orders[x]->GetMeal()->GetIngredientCount();
			RecipeItem** items = orders[x]->GetMeal()->GetItems(); // ingredients
			for (int y = 0; y < length; y++)
			{
				for (int i = 0; i < ingredient_count; i++)
				{
					if (items[y]->GetIngredient()->GetName() == ingredients[i]->GetIngredient()->GetName())
					{
						ingredients[i]->SetAmount(ingredients[i]->GetAmount() - orders[x]->GetMealCount() * items[y]->GetAmount());
					}
				}
			}
		}
	}
};

class Kitchen
{
private:
	Meal** meals;
	int meal_count;
	Order** orders;
	int order_count;
public:

#pragma region Constructors
	Kitchen() = delete;

	Kitchen(Meal**& meals, const int& meal_count, Order** orders, const int& order_count)
	{
		SetMealCount(meal_count);
		SetMeals(meals);
		SetOrderCount(order_count);
		SetOrders(orders);
	}
#pragma endregion

#pragma region Getters
	Meal** GetMeals() const
	{
		return meals;
	}
	int GetMealCount() const
	{
		return meal_count;
	}
	Order** GetOrders() const
	{
		return orders;
	}
	int GetOrderCount() const
	{
		return order_count;
	}
#pragma endregion

#pragma region Setters
	void SetMeals(Meal**& meals)
	{
		this->meals = meals;
	}
	void SetMealCount(const int& meal_count)
	{
		assert(meal_count >= 0 && "Meal count cannot be less than 0!");
		this->meal_count = meal_count;
	}
	void SetOrders(Order**& orders)
	{
		this->orders = orders;
	}
	void SetOrderCount(const int& order_count)
	{
		assert(order_count >= 0 && "Order count cannot be less than 0!");
		this->order_count = order_count;
	}
#pragma endregion

#pragma region Methods
	void ShowAllOrders()
	{
		cout << "================== ORDERS ==================" << endl;
		const int size = 20;
		bool hasShown[size]{};
		int length = GetOrderCount();
		for (int x = 0; x < length; x++)
		{
			int table_no = orders[x]->GetTableNo();
			SetColor(WHITE);
			if (!hasShown[table_no])
			{
				cout << "\n ============ TABLE NO " << table_no + 1 << " ============ " << endl;
				for (int y = 0; y < length; y++)
				{
					if (orders[y]->GetTableNo() == table_no)
					{
						orders[y]->ShowOrder();
					}
				}
				hasShown[table_no] = true;
			}
		}
	}

	void AddOrder(const Order& neworder)
	{
		Order** newOrders = new Order * [order_count + 1]{};
		for (int x = 0; x < order_count; x++)
		{
			newOrders[x] = orders[x];
		}
		if (order_count != 0)
		{
			delete[]orders;
		}
		newOrders[order_count] = new Order{ neworder };
		orders = newOrders;
		order_count++;
		newOrders = nullptr;
	}

	int GetOrderIndexByTableNo(const int& tableNo)
	{
		for (int x = 0; x < order_count; x++)
		{
			if (orders[x]->GetTableNo() == tableNo)
			{
				return x;
			}
		}
		throw InvalidArgumentException("There is no order in table", __FILE__, __LINE__, __DATE__);
	}

	int GetOrderCountInTableNo(const int& tableNo)
	{
		int counter = 0;
		for (int x = 0; x < order_count; x++)
		{
			if (orders[x]->GetTableNo() == tableNo)
			{
				counter++;
			}
		}
		return counter;
	}

	void DeleteOrderByTableNo(const int& tableNo)
	{
		int order_count_table = GetOrderCountInTableNo(tableNo);
		int i = 0;
		if (order_count > 0)
		{
			while (i < order_count_table)
			{
				int index = GetOrderIndexByTableNo(tableNo);
				Order** newOrders = new Order * [order_count - 1]{};
				for (int x = 0; x < index; x++)
				{
					newOrders[x] = orders[x];
				}
				for (int y = index + 1; y < order_count + 1; y++)
				{
					newOrders[y - 1] = orders[y];
				}
				delete[]orders;
				orders = newOrders;
				order_count--;
				newOrders = nullptr;
				i++;
			}
		}
		else
		{
			throw InvalidArgumentException("There is no order to delete", __FILE__,__LINE__,__DATE__);
		}
	}

	void ShowStock(const Stock& stock) const
	{
		stock.ShowAllIngredients();
	}
#pragma endregion

#pragma region Destructor
	~Kitchen()
	{
		for (int x = 0; x < meal_count; x++)
		{
			delete meals[x];
		}
		delete[]meals;
		for (int y = 0; y < order_count; y++)
		{
			delete orders[y];
		}
		delete[]orders;
	}
#pragma endregion
};

class Admin
{
private:
	string name;
	string password;
public:
#pragma region Constructors
	Admin() = default;

	Admin(const string & name, const string & password)
	{
		SetName(name);
		SetPassword(password);
	}
#pragma endregion

#pragma region Getters
	string GetName() const
	{
		return name;
	}
	string GetPassword() const
	{
		return password;
	}
#pragma endregion

#pragma region Setters
	void SetName(const string& name)
	{
		assert(!name.empty() && "Name should be filled!");
		this->name = name;
	}
	void SetPassword(const string& password)
	{
		assert(!password.empty() && "Password should be filled!");
		assert(password.length() >= 6 && "Password length should be at least 6 characters!");
		this->password = password;
	}
#pragma endregion

#pragma region Methods
	void ShowAdmin() const
	{
		cout << "====== ADMIN INFO ======" << endl;
		cout << "Name : " << GetName() << endl;
		cout << "Password : ";
		int length = password.length();
		for (int x = 0; x < length; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
#pragma endregion
};

class Restaruant
{
private:
	string name;
	string address;
	string city;
	double budget;
	Kitchen* kitchen;
	Stock* stock;
	Admin** admins;
	int admin_count;
	Table** tables;
	int table_count;
public:
#pragma region Constructors
	Restaruant() = delete;

	Restaruant(const string& name, const string& address, const string& city, Kitchen*& kitchen, Stock*& stock, Admin**& admins, const int& admin_count, Table** tables, const int& tableCount)
	{
		SetName(name);
		SetAddress(address);
		SetCity(city);
		SetBudget(0);
		SetKitchen(kitchen);
		SetStock(stock);
		SetAdminCount(admin_count);
		SetAdmins(admins);
		SetTables(tables);
		SetTableCount(tableCount);
	}
#pragma endregion

#pragma region Getters
	string GetName() const
	{
		return name;
	}
	string GetAddress() const
	{
		return address;
	}
	string GetCity() const
	{
		return city;
	}
	double GetBudget() const
	{
		return budget;
	}
	Kitchen* GetKitchen() const
	{
		return kitchen;
	}
	Stock* GetStock() const
	{
		return stock;
	}
	Admin** GetAdmins() const
	{
		return admins;
	}
	int GetAdminCount() const
	{
		return admin_count;
	}
	Table** GetTables() const
	{
		return tables;
	}
	int GetTableCount() const
	{
		return table_count;
	}
#pragma endregion

#pragma region Setters
	void SetName(const string& name)
	{
		assert(!name.empty() && "Restaruant name should be filled!");
		this->name = name;
	}
	void SetAddress(const string& address)
	{
		assert(!address.empty() && "Restaruant address should be filled!");
		this->address = address;
	}
	void SetCity(const string& city)
	{
		assert(!city.empty() && "City name should be filled!");
		this->city = city;
	}
	void SetBudget(const double& budget)
	{
		assert(budget >= 0 && "Budget cannot be less than 0!");
		this->budget = budget;
	}
	void SetKitchen(Kitchen*& kitchen)
	{
		this->kitchen = kitchen;
	}
	void SetStock(Stock*& stock)
	{
		this->stock = stock;
	}
	void SetAdmins(Admin**& admins)
	{
		this->admins = admins;
	}
	void SetAdminCount(const int& adminCount)
	{
		assert(adminCount >= 0 && "Admin count cannot be less than 0!");
		this->admin_count = adminCount;
	}
	void SetTables(Table**& tables)
	{
		this->tables = tables;
	}
	void SetTableCount(const int& tableCount)
	{
		assert(table_count >= 0 && "Table count cannot be less than 0!");
		this->table_count = table_count;
	}
#pragma endregion

#pragma region Methods
	void ShowRestaruant() const
	{
		cout << " ========= RESTARUANT ========= " << endl;
		cout << " Name : " << GetName() << endl;
		cout << " Address : " << GetAddress() << endl;
		cout << " City : " << GetCity() << endl;
		cout << " Budget : " << GetBudget() << endl;
	}

	bool IsAdmin(const string& name, const string& password) const
	{
		int length = GetAdminCount();
		for (int x = 0; x < length; x++)
		{
			if (admins[x]->GetName() == name)
			{
				if (admins[x]->GetPassword() == password)
				{
					return true;
				}
			}
		}
		return false;
	}
#pragma endregion

};