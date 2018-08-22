#include "parsehelper.h"

#include <script/script.h>
#include <serialize.h>
#include <utilstrencodings.h>

bool IsEqualScriptPubKeyHex(const CScript& script, const std::string& hexval) {
    std::string scriptHex;
    ScriptPubKeyToHex(script, scriptHex);
    return (scriptHex.compare(hexval) == 0);
}

void ScriptPubKeyToHex(const CScript& scriptPubKey, std::string& out)
{
     out = HexStr(scriptPubKey.begin(), scriptPubKey.end());
}

