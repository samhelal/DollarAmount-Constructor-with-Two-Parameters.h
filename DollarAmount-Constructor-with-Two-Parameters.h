/*5.30 ( DollarAmount Constructor with Two Parameters) Enhance class DollarAmount (Fig. 5.8) 
with a constructor that receives two parameters representing the whole number of dollars and 
the whole number of cents. Use these to calculateand store in the data member amount the total
number of pennies. Test the class with your new constructor. (c++ how to program)*/

#include <string>
#include <cmath>

class DollarAmount
{
public:
    // explicit DollarAmount(int64_t value) : amount{value} {}                // the old one constractor   
    DollarAmount(int64_t dollars, int64_t cents) : amount(dollars * 100)      // multiplay dollars by 100 to chang it to cents and save it to amount(the total by cents)
    {
        amount += cents;
    }

    void add(DollarAmount right)
    {
        amount += right.amount;
    }

    void subtract(DollarAmount right)
    {
        amount -= right.amount;
    }

    void addInterest(int rate, int divisor)
    {
        DollarAmount  interest{
           0, (amount * rate + divisor / 2) / divisor };                       //put 0 in the place of dollars constractor to match the calss of two constractors 
        add(interest);                                                         // to can add the two constractors of other classes 
    }

    std::string to_string() const
    {
        std::string dollars{std::to_string(amount / 100)};
        std::string cents{std::to_string(std::abs(amount % 100))};

        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    }

private:
    int64_t amount{0};
};