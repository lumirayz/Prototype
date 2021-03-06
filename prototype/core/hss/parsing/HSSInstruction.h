/********************************************************************
 *             a  A                                                        
 *            AM\/MA                                                         
 *           (MA:MMD                                                         
 *            :: VD
 *           ::  º                                                         
 *          ::                                                              
 *         ::   **      .A$MMMMND   AMMMD     AMMM6    MMMM  MMMM6             
 +       6::Z. TMMM    MMMMMMMMMDA   VMMMD   AMMM6     MMMMMMMMM6            
 *      6M:AMMJMMOD     V     MMMA    VMMMD AMMM6      MMMMMMM6              
 *      ::  TMMTMC         ___MMMM     VMMMMMMM6       MMMM                   
 *     MMM  TMMMTTM,     AMMMMMMMM      VMMMMM6        MMMM                  
 *    :: MM TMMTMMMD    MMMMMMMMMM       MMMMMM        MMMM                   
 *   ::   MMMTTMMM6    MMMMMMMMMMM      AMMMMMMD       MMMM                   
 *  :.     MMMMMM6    MMMM    MMMM     AMMMMMMMMD      MMMM                   
 *         TTMMT      MMMM    MMMM    AMMM6  MMMMD     MMMM                   
 *        TMMMM8       MMMMMMMMMMM   AMMM6    MMMMD    MMMM                   
 *       TMMMMMM$       MMMM6 MMMM  AMMM6      MMMMD   MMMM                   
 *      TMMM MMMM                                                           
 *     TMMM  .MMM                                         
 *     TMM   .MMD       ARBITRARY·······XML········RENDERING                           
 *     TMM    MMA       ====================================                              
 *     TMN    MM                               
 *      MN    ZM                       
 *            MM,
 *
 * 
 *      AUTHORS: Miro Keller
 *      
 *      COPYRIGHT: ©2011 - All Rights Reserved
 *
 *      LICENSE: see License.txt file
 *
 *      WEB: http://axr.vg
 *
 *      THIS CODE AND INFORMATION ARE PROVIDED "AS IS"
 *      WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
 *      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *      IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *      FITNESS FOR A PARTICULAR PURPOSE.
 *
 ********************************************************************
 *
 *      FILE INFORMATION:
 *      =================
 *      Last changed: 2012/03/29
 *      HSS version: 1.0
 *      Core version: 0.45
 *      Revision: 9
 *
 ********************************************************************/

#ifndef HSSINSTRUCTION_H
#define HSSINSTRUCTION_H

#include "HSSStatement.h"
#include <boost/shared_ptr.hpp>

namespace AXR {
    enum HSSInstructionType {
        HSSNewInstruction,
        HSSEnsureInstruction,
        HSSImportInstruction,
        HSSMoveInstruction,
        HSSDeleteInstruction,
        HSSGrayscale1Instruction,
        HSSGrayscale2Instruction,
        HSSRGBInstruction,
        HSSRGBAInstruction,
        HSSRRGGBBInstruction,
        HSSRRGGBBAAInstruction
    };
    
    class HSSInstruction : public HSSStatement
    {
    public:
        typedef boost::shared_ptr<HSSInstruction> p;
        
        HSSInstruction(HSSInstructionType type);
        HSSInstruction(HSSInstructionType type, std::string value);
        HSSInstruction(const HSSInstruction &orig);
        p clone() const;
        ~HSSInstruction();
        
        HSSInstructionType getInstructionType();
        std::string getValue();
        
        bool isA(HSSInstructionType type);
        
        static std::string instructionStringRepresentation(HSSInstructionType type);
        
        virtual std::string toString();
        
        void setArgument(HSSParserNode::p newValue);
        HSSParserNode::p getArgument();
        
    protected:
        HSSInstructionType instructionType;
        std::string value;
        HSSParserNode::p argument;
        
    private:
        virtual HSSClonable::p cloneImpl() const;
    };
}

#endif

