# Unit Converter

🧮 A command-line unit converter built in C. Supports length, weight, temperature, and currency conversions.

## 🔧 Features

- ✅ Length conversion (meter, inch, km, mile)
- ✅ Weight conversion (kg, lb, gr, ons)
- ✅ Temperature conversion (C, F, K)
- ✅ Currency conversion (USD, EUR, GBP, TRY) — static rates

## 🚀 Usage

Compile the project using `make`:

```bash
make

./unit-converter --type=TYPE --from=UNIT1 --to=UNIT2 --value=VALUE
./unit-converter --type=length --from=meter --to=inch --value=2
./unit-converter --type=weight --from=kg --to=lb --value=5
./unit-converter --type=temperature --from=C --to=F --value=100
./unit-converter --type=currency --from=USD --to=TRY --value=5

```
📁 Project Structure:

```css
.
├── main.c
├──unit_converter.c
├──unit_converter.h
├── Makefile
├── README.md
└── .gitignore

```
⚠️ Notes
- Currency rates are hardcoded and not fetched from live APIs.

- For currency accuracy, consider integrating an API like ExchangeRate API.

