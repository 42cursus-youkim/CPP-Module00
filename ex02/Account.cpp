#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(++_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0){};

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

void Account::displayAccountsInfos(void) {
  std::cout << "accounts:" << _nbAccounts << std::endl;
  std::cout << "total:" << _totalAmount << std::endl;
  std::cout << "deposits:" << _totalNbDeposits << std::endl;
  std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

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

void Account::_displayTimestamp(void) {
  const std::time_t rawtime = time(NULL);
  const tm t = *localtime(&rawtime);

  const int year = t.tm_year + 1900;
  const int dateMonth[2] = {t.tm_mon + 1, t.tm_mday};
  const int dateDay[3] = {t.tm_hour, t.tm_min, t.tm_sec};

  std::cout << "[" << year << formatTimes(2, dateMonth) << "_"
            << formatTimes(3, dateDay) << "] ";
}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ": deposit: " << deposit
            << std::endl;
  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ": withdrawal: " << withdrawal
            << std::endl;
  if (_amount < withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ": overdrawn" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _nbWithdrawals++;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  return true;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ", amount:" << _amount
            << ", deposits:" << _nbDeposits
            << ", withdrawals:" << _nbWithdrawals << std::endl;
}
