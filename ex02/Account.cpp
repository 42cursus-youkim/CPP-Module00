#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/*
  Helper Functions
*/
static std::string formatTime(const int num) {
  std::ostringstream stream;
  stream << std::setfill('0') << std::setw(2) << num;
  return stream.str();
}

static std::string formatTimes(const int size, const int nums[]) {
  std::ostringstream stream;
  for (int i = 0; i < size; i++) {
    stream << formatTime(nums[i]);
  }
  return stream.str();
}

static std::string formatInfo(const std::string& str, size_t val) {
  std::ostringstream stream;

  stream << str << ":" << val << ";";
  return stream.str();
}

static std::string formatInfoLast(const std::string& str, size_t val) {
  std::ostringstream stream;

  stream << str << ":" << val << "\n";
  return stream.str();
}

/*
  Account
*/

/* Initial setup */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Constructor & Destructor */
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << formatInfo("index", _accountIndex)
            << formatInfo("amount", _amount) << "created\n";
};

Account::~Account(void) {
  _displayTimestamp();
  std::cout << formatInfo("index", _accountIndex)
            << formatInfo("amount", _amount) << "closed\n";
}

/* Getter */
int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

int Account::checkAmount(void) const {
  return _amount;
}

/* Print */
void Account::_displayTimestamp(void) {
  const std::time_t rawtime = time(NULL);
  const tm t = *localtime(&rawtime);

  const int year = t.tm_year + 1900;
  const int dateMonth[2] = {t.tm_mon + 1, t.tm_mday};
  const int dateDay[3] = {t.tm_hour, t.tm_min, t.tm_sec};

  std::cout << "[" << year << formatTimes(2, dateMonth) << "_"
            << formatTimes(3, dateDay) << "] ";
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << formatInfo("accounts", _nbAccounts)
            << formatInfo("total", _totalAmount)
            << formatInfo("deposits", _totalNbDeposits)
            << formatInfoLast("withdrawals", _totalNbWithdrawals);
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << formatInfo("index", _accountIndex)
            << formatInfo("amount", _amount)
            << formatInfo("deposits", _nbDeposits)
            << formatInfoLast("withdrawals", _nbWithdrawals);
}

/* Methods */
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  _nbDeposits++;
  std::cout << formatInfo("index", _accountIndex)
            << formatInfo("p_amount", _amount) << formatInfo("deposit", deposit)
            << formatInfo("amount", _amount + deposit)
            << formatInfoLast("nb_deposits", _nbDeposits);
  _amount += deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << formatInfo("index", _accountIndex)
            << formatInfo("p_amount", _amount);
  if (_amount >= withdrawal) {
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << formatInfo("withdrawal", withdrawal)
              << formatInfo("amount", _amount)
              << formatInfoLast("nb_withdrawals", ++_nbWithdrawals);
    return true;
  } else {
    std::cout << "withdrawal:refused\n";
    return false;
  }
}
