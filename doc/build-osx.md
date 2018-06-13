Mac OS X Build Instructions and Notes
====================================
The commands in this guide should be executed in a Terminal application.
The built-in one is located in `/Applications/Utilities/Terminal.app`.

Preparation
-----------
Install the OS X command line tools:

`xcode-select --install`

When the popup appears, click `Install`.

Then install [Homebrew](https://brew.sh).

Dependencies
----------------------

<<<<<<< HEAD
    brew install automake berkeley-db4 libtool boost --c++11 miniupnpc openssl pkg-config protobuf qt libevent
=======
    brew install automake berkeley-db4 libtool boost miniupnpc openssl pkg-config protobuf python3 qt libevent

See [dependencies.md](dependencies.md) for a complete overview.
>>>>>>> upstream/0.16

If you want to build the disk image with `make deploy` (.dmg / optional), you need RSVG

    brew install librsvg

If you want to build with ZeroMQ support
    
    brew install zeromq

NOTE: Building with Qt4 is still supported, however, could result in a broken UI. Building with Qt5 is recommended.

<<<<<<< HEAD
Build Actinium Core
------------------------

1. Clone the Actinium source code and cd into `Actinium`

        git clone https://github.com/Actinium-project/Actinium
        cd Actinium

2.  Build Actinium-core:

    Configure and build the headless Actinium binaries as well as the GUI (if Qt is found).
=======
Berkeley DB
-----------
It is recommended to use Berkeley DB 4.8. If you have to build it yourself,
you can use [the installation script included in contrib/](/contrib/install_db4.sh)
like so

```shell
./contrib/install_db4.sh .
```

from the root of the repository.

**Note**: You only need Berkeley DB if the wallet is enabled (see the section *Disable-Wallet mode* below).

Build Litecoin Core
------------------------

1. Clone the litecoin source code and cd into `litecoin`

        git clone https://github.com/litecoin-project/litecoin
        cd litecoin

2.  Build litecoin-core:

    Configure and build the headless litecoin binaries as well as the GUI (if Qt is found).
>>>>>>> upstream/0.16

    You can disable the GUI build by passing `--without-gui` to configure.

        ./autogen.sh
        ./configure
        make

3.  It is recommended to build and run the unit tests:

        make check

4.  You can also create a .dmg that contains the .app bundle (optional):

        make deploy

Running
-------

<<<<<<< HEAD
Actinium Core is now available at `./src/Actiniumd`

Before running, it's recommended you create an RPC configuration file.

    echo -e "rpcuser=litecoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Actinium/Actinium.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/Actinium/Actinium.conf"

The first time you run Actiniumd, it will start downloading the blockchain. This process could take several hours.

You can monitor the download process by looking at the debug.log file:

    tail -f $HOME/Library/Application\ Support/Actinium/debug.log
=======
Litecoin Core is now available at `./src/litecoind`

Before running, it's recommended you create an RPC configuration file.

    echo -e "rpcuser=litecoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"

    chmod 600 "/Users/${USER}/Library/Application Support/Litecoin/litecoin.conf"

The first time you run litecoind, it will start downloading the blockchain. This process could take several hours.

You can monitor the download process by looking at the debug.log file:

    tail -f $HOME/Library/Application\ Support/Litecoin/debug.log
>>>>>>> upstream/0.16

Other commands:
-------

<<<<<<< HEAD
    ./src/Actiniumd -daemon # Starts the Actinium daemon.
    ./src/Actinium-cli --help # Outputs a list of command-line options.
    ./src/Actinium-cli help # Outputs a list of RPC commands when the daemon is running.

Using Qt Creator as IDE
------------------------
You can use Qt Creator as an IDE, for Actinium development.
=======
    ./src/litecoind -daemon # Starts the litecoin daemon.
    ./src/litecoin-cli --help # Outputs a list of command-line options.
    ./src/litecoin-cli help # Outputs a list of RPC commands when the daemon is running.

Using Qt Creator as IDE
------------------------
You can use Qt Creator as an IDE, for litecoin development.
>>>>>>> upstream/0.16
Download and install the community edition of [Qt Creator](https://www.qt.io/download/).
Uncheck everything except Qt Creator during the installation process.

1. Make sure you installed everything through Homebrew mentioned above
2. Do a proper ./configure --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
<<<<<<< HEAD
4. Enter "Actinium-qt" as project name, enter src/qt as location
=======
4. Enter "litecoin-qt" as project name, enter src/qt as location
>>>>>>> upstream/0.16
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installation)
10. Start debugging with Qt Creator

Notes
-----

<<<<<<< HEAD
* Tested on OS X 10.8 through 10.12 on 64-bit Intel processors only.
=======
* Tested on OS X 10.8 through 10.13 on 64-bit Intel processors only.
>>>>>>> upstream/0.16

* Building with downloaded Qt binaries is not officially supported. See the notes in [#7714](https://github.com/bitcoin/bitcoin/issues/7714)
