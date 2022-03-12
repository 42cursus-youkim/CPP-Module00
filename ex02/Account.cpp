#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {}

int Account::getTotalAmount(void) {}

int Account::getNbDeposits(void) {}

int Account::getNbWithdrawals(void) {}

void Account::displayAccountsInfos(void){
  _displayTimestamp();
}

Account::Account(int initial_deposit)
    : _accountIndex(++_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0){};

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {}

bool Account::makeWithdrawal(int withdrawal) {}

int Account::checkAmount(void) const {}

void Account::displayStatus(void) const {}
