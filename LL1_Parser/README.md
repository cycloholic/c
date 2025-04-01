# 🧠 LL(1) Syntax Analyzer (C++)

This is a simple recursive descent parser for math expressions, written in C++.  
It checks whether an expression is syntactically valid, based on a basic LL(1) grammar.

---

## 📚 Grammar


---

## 🚀 Compile & Run

```bash
g++ main.cpp Parser.cpp -o parser
./parser
```

Enter expression: (2 + 3) * 5
✅ Valid expression

Enter expression: 7 + * 2
❌ Syntax error: Unexpected character in factor
