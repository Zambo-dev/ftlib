# ftlib

file-tracer is a C library for local file searching.

## Installation

Just clone the directory and include the C file in your project
This branch of ftlib is made for windows/linux and search only on the main disk / root partition, if you want to search on multiple disk check out ftlib docs and use the specific fucntions

## How to use

```bash
# Compile
gcc -O -lpthread main.c -o ftcli

# Then set .exe (or linux executable) file in the system path

# Usage
ftcli filename_to_be_searched

```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://github.com/Zambo-dev/ftlib/blob/master/LICENSE)
