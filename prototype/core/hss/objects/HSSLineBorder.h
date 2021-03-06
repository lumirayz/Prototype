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
 *      Last changed: 2012/03/25
 *      HSS version: 1.0
 *      Core version: 0.46
 *      Revision: 10
 *
 ********************************************************************/

#ifndef HSSLINEBORDER_H
#define HSSLINEBORDER_H

#include <string>
#include "HSSBorder.h"
#include <boost/shared_ptr.hpp>
#include "HSSRgb.h"

namespace AXR {
    class HSSLineBorder : public HSSBorder
    {
    public:
        typedef boost::shared_ptr<HSSLineBorder> p;
        
        /**
         *  Constructor for HSSLineBorder objects
         */
        HSSLineBorder();
        /**
         *  Copy constructor for HSSLineBorder objects
         */
        HSSLineBorder(const HSSLineBorder & orig);
        /**
         *  Clones an instance of HSSLineBorder and gives a shared pointer of the
         *  newly instanciated object.
         *  @return A shared pointer to the new HSSLineBorder
         */
        p clone() const;
        virtual ~HSSLineBorder();
        
        virtual std::string toString();
        virtual std::string defaultObjectType();
        virtual std::string defaultObjectType(std::string property);
        virtual bool isKeyword(std::string value, std::string property);
        
        virtual void setProperty(HSSObservableProperty name, HSSParserNode::p value);
        
        //color
        HSSObject::p getColor();
        void setDColor(HSSParserNode::p);
        void colorChanged(HSSObservableProperty source, void*data);
        
        virtual void draw(cairo_t * cairo);
        
    protected:
        //color
        HSSRgb::p color;
        HSSParserNode::p dColor;
        HSSObservable * observedColor;
        HSSObservableProperty observedColorProperty;
    private:
        HSSClonable::p cloneImpl() const;
    };
}


#endif
