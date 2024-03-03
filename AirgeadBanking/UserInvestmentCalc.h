#ifndef AIRGEADBANKING_USERINVESTMENTCALC_H
#define AIRGEADBANKING_USERINVESTMENTCALC_H

#include "UserInvestment.h"

class UserDataCalculations {

public:
    // Function prototype for report calculations
    static void dataWithoutDeposits(UserInvestment t_userInvestment);
    static void dataWithDeposits(UserInvestment t_userInvestment);
};

#endif //AIRGEADBANKING_USERINVESTMENTCALC_H
