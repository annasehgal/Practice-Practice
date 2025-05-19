# Temperature Converter with Emscripten

This project provides a simple temperature converter between Fahrenheit and Celsius using C++ compiled to WebAssembly with Emscripten.

---

## Files

- `converter.cpp` — C++ source code for temperature conversion functions.
- `index.html` — Simple webpage to interact with the converter.
- `styles.css` — Stylesheet to make the page prettier.
- `converter.js` and `converter.wasm` — Generated WebAssembly and JavaScript files (excluded from repo).

---

## How to Build

If you want to rebuild the WebAssembly files (`converter.js` and `converter.wasm`), make sure you have [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) installed and activated, then run:

```bash
emcc converter.cpp -o converter.js -s EXPORTED_FUNCTIONS='["_CelsiusToF","_FahrenheitToC"]' -s MODULARIZE=1 -s 'EXPORT_NAME="createModule"'
```

## How to Run

Because WebAssembly files must be loaded over a web server (not via direct file:// URLs), you need to serve the files locally. You can easily do this with Python:

1. Open a terminal and navigate to your project directory where `index.html` is located.

2. Run the following command to start a local HTTP server bound to localhost:

   ```bash
   python3 -m http.server --bind 127.0.0.1
   ```
3. Open your browser and go to:
    ```bash
    http://127.0.0.1:8000/index.html
    ```
4. You should see your temperature converter page. Use it to convert temperatures between Fahrenheit and Celsius.

5. When done, stop the server by pressing Ctrl + C in the terminal.