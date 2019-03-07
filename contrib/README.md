Repository Tools
---------------------

### [Developer tools](/contrib/devtools) ###
Specific tools for developers working on this repository.
Contains the script `github-merge.py` for merging GitHub pull requests securely and signing them using GPG.

### [Verify-Commits](/contrib/verify-commits) ###
Tool to verify that every merge commit was signed by a developer using the above `github-merge.py` script.

### [Linearize](/contrib/linearize) ###
Construct a linear, no-fork, best version of the blockchain.

### [Qos](/contrib/qos) ###

<<<<<<< HEAD
A Linux bash script that will set up traffic control (tc) to limit the outgoing bandwidth for connections to the Actinium network. This means one can have an always-on Actiniumd instance running, and another local Actiniumd/Actinium-qt instance which connects to this node and receives blocks from it.
=======
A Linux bash script that will set up traffic control (tc) to limit the outgoing bandwidth for connections to the Litecoin network. This means one can have an always-on litecoind instance running, and another local litecoind/litecoin-qt instance which connects to this node and receives blocks from it.
>>>>>>> f22cd116c597213753b8cc77ff675ed5be18ec1d

### [Seeds](/contrib/seeds) ###
Utility to generate the pnSeed[] array that is compiled into the client.

Build Tools and Keys
---------------------

<<<<<<< HEAD
### [Debian](/contrib/debian) ###
Contains files used to package Actiniumd/Actinium-qt
for Debian-based Linux systems. If you compile Actiniumd/Actinium-qt yourself, there are some useful files here.
=======
### Packaging ###
The [Debian](/contrib/debian) subfolder contains the copyright file.

All other packaging related files can be found in the [bitcoin-core/packaging](https://github.com/bitcoin-core/packaging) repository.
>>>>>>> f22cd116c597213753b8cc77ff675ed5be18ec1d

### [Gitian-descriptors](/contrib/gitian-descriptors) ###
Files used during the gitian build process. For more information about gitian, see the [the Bitcoin Core documentation repository](https://github.com/bitcoin-core/docs).

### [Gitian-keys](/contrib/gitian-keys)
<<<<<<< HEAD
PGP keys used for signing Actinium Core [Gitian release](/doc/release-process.md) results.
=======
PGP keys used for signing Litecoin Core [Gitian release](/doc/release-process.md) results.
>>>>>>> f22cd116c597213753b8cc77ff675ed5be18ec1d

### [MacDeploy](/contrib/macdeploy) ###
Scripts and notes for Mac builds. 

<<<<<<< HEAD
### [RPM](/contrib/rpm) ###
RPM spec file for building bActinium-core on RPM based distributions.

### [Gitian-build](/contrib/gitian-build.sh) ###
=======
### [Gitian-build](/contrib/gitian-build.py) ###
>>>>>>> f22cd116c597213753b8cc77ff675ed5be18ec1d
Script for running full Gitian builds.

Test and Verify Tools 
---------------------

### [TestGen](/contrib/testgen) ###
<<<<<<< HEAD
Utilities to generate test vectors for the data-driven Actinium tests.

### [Verify Binaries](/contrib/verifybinaries) ###
This script attempts to download and verify the signature file SHA256SUMS.asc from Actinium.org.
=======
Utilities to generate test vectors for the data-driven Litecoin tests.

### [Verify Binaries](/contrib/verifybinaries) ###
This script attempts to download and verify the signature file SHA256SUMS.asc from litecoin.org.
>>>>>>> f22cd116c597213753b8cc77ff675ed5be18ec1d
