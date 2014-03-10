#include "compiler/rules/string.h"
#include "compiler/rules/visitor.h"

namespace tree_sitter  {
    using std::string;
    using std::hash;
    
    namespace rules {
        String::String(string value) : value(value) {};

        bool String::operator==(const Rule &rule) const {
            const String *other = dynamic_cast<const String *>(&rule);
            return other && (other->value == value);
        }

        size_t String::hash_code() const {
            return hash<string>()(value);
        }

        rule_ptr String::copy() const {
            return std::make_shared<String>(*this);
        }

        string String::to_string() const {
            return string("#<string '") + value + "'>";
        }

        void String::accept(Visitor *visitor) const {
            visitor->visit(this);
        }
    }
}