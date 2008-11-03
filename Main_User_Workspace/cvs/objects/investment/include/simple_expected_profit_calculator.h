#ifndef _SIMPLE_EXPECTED_PROFIT_CALCULATOR_H_
#define _SIMPLE_EXPECTED_PROFIT_CALCULATOR_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * All rights to use the Software are granted on condition that such
 * rights are forfeited if User fails to comply with the terms of
 * this Agreement.
 * 
 * User agrees to identify, defend and hold harmless BATTELLE,
 * its officers, agents and employees from all liability involving
 * the violation of such Export Laws, either directly or indirectly,
 * by User.
 */

/*! 
* \file simple_expected_profit_calculator.h
* \ingroup Objects
* \brief The SimpleExpectedProfitCalculator class header file.
* \author Josh Lurz
*/
#include <iosfwd>
#include "investment/include/iexpected_profit_calculator.h"
class IInvestable;
class Tabs;

/*! 
 * \ingroup Objects
 * \brief This object calculates expected profits across a sector or subsector
 *        using a logit formulation.
 * \details TODO
 * \author Josh Lurz
 */
class SimpleExpectedProfitCalculator: public IExpectedProfitRateCalculator
{
public:
    SimpleExpectedProfitCalculator();
    static const std::string& getXMLNameStatic();
    void toInputXML( std::ostream& aOut, Tabs* aTabs ) const;
    void toDebugXML( const int aPeriod, std::ostream& aOut, Tabs* aTabs ) const;
    
    double calcSectorExpectedProfitRate( const std::vector<IInvestable*>& aInvestables,
                                         const NationalAccount& aNationalAccount,
                                         const std::string& aRegionName,
                                         const std::string& aGoodName,
                                         const double aInvestmentLogitExp,
                                         const bool aIsShareCalc,
                                         const int aPeriod ) const;

    double calcTechnologyExpectedProfitRate( const ProductionFunctionInfo& aTechProdFuncInfo,
                                             const NationalAccount& aNationalAccount,
                                             const std::string& aRegionName,
                                             const std::string& aSectorName,
                                             const double aDelayedInvestmentTime,
                                             const int aLifetime,
                                             const int aTimeStep,
                                             const int aPeriod ) const;
};

#endif // _SIMPLE_EXPECTED_PROFIT_CALCULATOR_H_