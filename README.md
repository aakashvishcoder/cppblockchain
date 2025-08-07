# Blockchain

## General Process

<p>Blockchain and other architectures captivated me. I have been interested in cybersecurity and was intrigued by how structures like this keep data encrypted and protected. As a result, I came up with the idea of making my own blockchain architecture. I could have created this using virtually any language, but I chose C++ as it is one of my preferred languages, and it has exceptional memory handling and speed compared to other languages.</p>
<p>To make the blockchain architecture, I first researched the components that make up the architecture and modeled it out. Then, using struct, I created a block that stores the data and creates hashes to encrypt the data. Lastly, I <b>chained</b> blocks together by creating a blockchain class and implemented more functions to tie it all together.</p>

## Complications

<p>While creating this project, I had some important decisions to make. For example, blockchains could be implemented using vectors or using linked lists via structs. As I felt it was better represented using a linked list (representing each block as a node), I decided to use structs. Additionally, in order to use C++ to its full potential, I had to make sure that the memory was well managed. I do believe that the memory management could be improved in this project, but for the purpose of understanding blockchains, this project fufills its purpose.</p>

## Tech Stack

- C++

## How to Use

<p>To run this code, you need to have a C++ compiler installed. I reccomend following this <a href="https://code.visualstudio.com/docs/languages/cpp">tutorial</a>. Even if you have a different code editor, follow this tutorial to download <a href="https://www.mingw-w64.org/">MinGW</a> and run the code below in your terminal.</p>

```bash
git clone https://github.com/aakashvishcoder/mini-sql-database.git
cd your-repo
g++ blockchain.cpp -o run
./run         # On Linux/macOS
run.exe       # On Windows
