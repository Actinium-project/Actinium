// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_PARSEHELPER_H
#define BITCOIN_PARSEHELPER_H

#include <string>

class CScript;

bool IsEqualScriptPubKeyHex(const CScript& script, const std::string& hexval) ;
CScript ParseScript(const std::string& s);
void ScriptPubKeyToHex(const CScript& scriptPubKey, std::string& out);

#endif // BITCOIN_PARSEHELPER_H

