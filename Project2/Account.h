// Specification file for the Account class
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        double balance; // Account balance
        double interestRate; // Interest rate for the period
        double interest; // Interest earned for the period
        int transactions; // Number of transactions
        double investmentAmount; //Total amount invested
        double retirementAmount; //Stores total retirement fund

    public:
        Account(double iRate = 0.045, double bal = 0)
        { 
            balance = bal;
            interestRate = iRate;
            interest= 0;
            transactions = 0;
            investmentAmount = 0;
            retirementAmount = 0;
        }
        
        void setInterestRate(double iRate)
        { interestRate = iRate; }
        
        void makeDeposit(double amount)
        {
            balance += amount; transactions++; 
        }
        
        bool withdraw(double amount)
        {
            if (balance < amount)
                return false; // Not enough in the account
            else
            {
                balance -= amount;
                transactions++;
                return true;
            }
        }
        
        void calcInterest()
        {
            interest = balance * interestRate; balance += interest; 
        }
        
        double getInterestRate() const
        {
            return interestRate; 
        }
        
        double getBalance() const
        {
            return balance; 
        }
        
        double getInterest() const
        {
            return interest; 
        }

        int getTransactions() const
        {
            return transactions; 
        }

        bool makeInvestment(double amount)
        {
            if(withdraw(amount))
            {
                investmentAmount += amount;
                transactions++;
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool withdrawInvestment(double amount)
        {
            if (investmentAmount < amount)
                return false; // Not enough in the account
            else
            {
                investmentAmount -= amount;
                balance += amount;
                transactions++;
                return true;
            }
        }
        
        double getInvestmentAmount() const
        {   
            return investmentAmount;
        }

        bool contributeRetirementFund(double amount)
        {
            if(withdraw(amount))
            {
                retirementAmount += amount;
                transactions++;
                return true;
            }
            else
            {
                return false;
            }
        }

        double getRetirementAmount() const
        {   
            return retirementAmount;
        }

};
#endif
