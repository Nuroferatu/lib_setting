//                                    .-""-.
//                                   / _  _ \
//                                   |(_)(_)|
// .------------------------------ooO(_ /\ _)Ooo-----------------------------.
// |                                  |====|                                 |
// |                                  '-..-'                                 |
// | Desc: Settings library                                                  |
// | By: Nuroferatu - https://github.com/Nuroferatu                          |
// |                                                                         |
// | Copyright (C)2019 SoftwareToolsFactory                                  |
// |                   http://softwaretoolsfactory.com                       |
// '-------------------------------------------------------------------------'
// ----= Change log =---------------------------------------------------------
//     2. 2020.03.01, 15:00 Nuroferatu   [+] riseInvalidTypeError - throws runtime_error with type info
//                                       [*] asXXX mothods throw when invalid type is detected (casting is not supported by design)
//     1. 2019.11.11, 13:00 Nuroferatu   [+] Initial
// ---------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include "settings.h"

using namespace stf;

std::ostream& stf::operator << ( std::ostream& out, eSettingLevel level ) {
    switch (level) {
        case eSettingLevel::APP: out << "APP"; break;
        case eSettingLevel::SYS: out << "SYS"; break;
        case eSettingLevel::USER: out << "USER"; break;
    }
    return out;
}

std::ostream& stf::operator << ( std::ostream& out, eSettingType type ) {
    switch (type) {
        case eSettingType::BOOL: out << "BOOL"; break;
        case eSettingType::INT: out << "INT"; break;
        case eSettingType::FLOAT: out << "FLOAT"; break;
        case eSettingType::STRING: out << "STRING"; break;
    }
    return out;
}

bool SettingParam::asBool( void ) const {
    if (_type != eSettingType::BOOL)
        riseInvalidTypeError( "asBool", eSettingType::BOOL );

    return _val.bVal;
}

int SettingParam::asInt( void ) const {
    if (_type != eSettingType::INT)
        riseInvalidTypeError( "asInt", eSettingType::INT );

    return _val.iVal;
}

float SettingParam::asFloat( void ) const {
    if (_type != eSettingType::FLOAT)
        riseInvalidTypeError( "asFloat", eSettingType::FLOAT );

    return _val.fVal;
}

const std::string& SettingParam::asStr( void ) const {
    return _strVal;
}

void SettingParam::riseInvalidTypeError( const std::string& method, const stf::eSettingType expectedType ) const {
    std::stringstream exceptionMsg;
    exceptionMsg << method << " failed for param: '" << _name << "' expected type '" << expectedType  << "' but param is '" << _type;
    throw std::runtime_error( exceptionMsg.str() );
}

void Settings::addParam( SettingParam& param ) {
    std::cout << "Settings::addparam '" << param.getName() << "' of type '" << param.getType() << "' and level '" << param.getLevel() << "' with default value of '" << param.getDefaultVal() << "'\n";
}

void Settings::loadSysConfig( const std::string& appName ) {
}

void Settings::loadUsrConfig( const std::string& appName ) {
}

// vim: ts=4:sw=4:et:nowrap
/* EOF */
