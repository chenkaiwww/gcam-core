#ifndef _CARBON_MODEL_UTILS_H_
#define _CARBON_MODEL_UTILS_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
* This software, which is provided in confidence, was prepared by employees of
* Pacific Northwest National Laboratory operated by Battelle Memorial Institute.
* Battelle has certain unperfected rights in the software which should not be
* copied or otherwise disseminated outside your organization without the express
* written authorization from Battelle. All rights to the software are reserved
* by Battelle. Battelle makes no warranty, express or implied, and assumes no
* liability or responsibility for the use of this software.
*/

/*! 
 * \file carbon_model_utils.h
 * \ingroup Objects
 * \brief The CarbonModelUtils class header file.
 * \author Jim Naslund and Ming Chang
 */

#include "util/base/include/time_vector.h"
#include "land_allocator/include/aland_allocator_item.h"

class LandUseHistory;

/*!
* \brief enum denoting types of carbon flows between boxes.
*/
enum FlowType {
    /*!
     * \brief Box flow - carbon flow due to plant growht, decay, etc..
     */
    eBoxFlow,
    /*!
     * \brief Flow due to land-use change
    */
    eLUCFlow,
    /*!
     * \brief Flow of carbon out due to a decrease in land area
    */
    eLUCFlowOut,
    /*!
     * \brief Flow of carbon in due to an increase in land area
    */
    eLUCFlowIn,
    /*!
     * \brief Any type of flow
    */
    eAnyFlow
};

/*!
* \brief enum denoting types of carbon boxes.
*/
enum BoxType {
    /*!
     * \brief Vegetation type.
     */
    eVegetation,
    /*!
     * \brief Soil type.
     */
    eSoil,
    /*!
     * \brief Litter type.
     */
    eLitter,
    /*!
     * \brief NPP type.
     */
     eNPP,
     /*!
      * \brief Atmosphere type.
      */
      eAtmosphere,
     /*!
      * \brief A box should never be assigned type, it is used in the code
      *        to perform operations on any of the above box types.
      */
     eAnyBox
};

/*
 * \brief Class with static helper functions for carbon models.
 * \author Jim Naslund
 */
class CarbonModelUtils {
public:
    CarbonModelUtils();
    ~CarbonModelUtils();

    static double getLandUse( const unsigned int aYear,
                              const LandUseHistory* aLandUseHistory,
                              const double aHistoricalShare,
                              const objects::PeriodVector<double>& aLandUse );

    static double getSoilTimeScale();
    static const int getStartYear();
    static const int getEndYear();

    static const int getConceptualRootKey(const ALandAllocatorItem* const aItem );

    static double interpYearHelper( const objects::PeriodVector<double>& aPeriodVector,
                                    const unsigned int aYear );

    static double interpYearHelper( const objects::YearVector<double>& aYearVector,
                                    const unsigned int aStartYear,
                                    const unsigned int aEndYear,
                                    const unsigned int aYear );
    static std::string flowTypeToString( FlowType aFlow );
    static std::string boxTypeToString( BoxType aBoxType );
    static BoxType stringBoxNameToType( const std::string aBoxName );
};

#endif // _CARBON_MODEL_UTILS_H_