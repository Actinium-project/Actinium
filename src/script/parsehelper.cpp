#include "parsehelper.h"

#include <primitives/block.h>
#include <primitives/transaction.h>
#include <script/script.h>
#include <serialize.h>
#include <streams.h>
#include <utilstrencodings.h>
#include <version.h>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <util.h>

bool IsEqualScriptPubKeyHex(const CScript& script, const std::string& hexval) {
    std::string scriptHex;
    ScriptPubKeyToHex(script, scriptHex);
    return (scriptHex.compare(hexval) == 0);
}

CScript ParseScript(const std::string& s)
{
    CScript result;

    static std::map<std::string, opcodetype> mapOpNames;

    if (mapOpNames.empty())
    {
        for (unsigned int op = 0; op <= MAX_OPCODE; op++)
        {
            // Allow OP_RESERVED to get into mapOpNames
            if (op < OP_NOP && op != OP_RESERVED)
                continue;

            const char* name = GetOpName((opcodetype)op);
            if (strcmp(name, "OP_UNKNOWN") == 0)
                continue;
            std::string strName(name);
            mapOpNames[strName] = (opcodetype)op;
            // Convenience: OP_ADD and just ADD are both recognized:
            boost::algorithm::replace_first(strName, "OP_", "");
            mapOpNames[strName] = (opcodetype)op;
        }
    }

    std::vector<std::string> words;
    boost::algorithm::split(words, s, boost::algorithm::is_any_of(" \t\n"), boost::algorithm::token_compress_on);

    for (std::vector<std::string>::const_iterator w = words.begin(); w != words.end(); ++w)
    {
        if (w->empty())
        {
            // Empty string, ignore. (boost::split given '' will return one word)
        }
        else if (all(*w, boost::algorithm::is_digit()) ||
            (boost::algorithm::starts_with(*w, "-") && all(std::string(w->begin()+1, w->end()), boost::algorithm::is_digit())))
        {
            // Number
            int64_t n = atoi64(*w);
            result << n;
        }
        else if (boost::algorithm::starts_with(*w, "0x") && (w->begin()+2 != w->end()) && IsHex(std::string(w->begin()+2, w->end())))
        {
            // Raw hex data, inserted NOT pushed onto stack:
            std::vector<unsigned char> raw = ParseHex(std::string(w->begin()+2, w->end()));
            result.insert(result.end(), raw.begin(), raw.end());
        }
        else if (w->size() >= 2 && boost::algorithm::starts_with(*w, "'") && boost::algorithm::ends_with(*w, "'"))
        {
            // Single-quoted string, pushed as data. NOTE: this is poor-man's
            // parsing, spaces/tabs/newlines in single-quoted strings won't work.
            std::vector<unsigned char> value(w->begin()+1, w->end()-1);
            result << value;
        }
        else if (mapOpNames.count(*w))
        {
            // opcode, e.g. OP_ADD or ADD:
            result << mapOpNames[*w];
        }
        else
        {
            throw std::runtime_error("script parse error");
        }
    }

    return result;
}

void ScriptPubKeyToHex(const CScript& scriptPubKey, std::string& out)
{
     out = HexStr(scriptPubKey.begin(), scriptPubKey.end());
}

