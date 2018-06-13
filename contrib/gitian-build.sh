# Copyright (c) 2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

# What to do
sign=false
verify=false
build=false
<<<<<<< HEAD
setupenv=false
=======
>>>>>>> upstream/0.16

# Systems to build
linux=true
windows=true
osx=true

# Other Basic variables
SIGNER=
VERSION=
commit=false
<<<<<<< HEAD
url=https://github.com/Actinium-project/Actinium
=======
url=https://github.com/litecoin-project/litecoin
>>>>>>> upstream/0.16
proc=2
mem=2000
lxc=true
osslTarUrl=http://downloads.sourceforge.net/project/osslsigncode/osslsigncode/osslsigncode-1.7.1.tar.gz
osslPatchUrl=https://bitcoincore.org/cfields/osslsigncode-Backports-to-1.7.1.patch
scriptName=$(basename -- "$0")
signProg="gpg --detach-sign"
commitFiles=true

# Help Message
read -d '' usage <<- EOF
Usage: $scriptName [-c|u|v|b|s|B|o|h|j|m|] signer version

<<<<<<< HEAD
Run this script from the directory containing the Actinium, gitian-builder, gitian.sigs.ltc, and Actinium-detached-sigs.
=======
Run this script from the directory containing the litecoin, gitian-builder, gitian.sigs.ltc, and litecoin-detached-sigs.
>>>>>>> upstream/0.16

Arguments:
signer          GPG signer to sign each build assert file
version		Version number, commit, or branch to build. If building a commit or branch, the -c option must be specified

Options:
-c|--commit	Indicate that the version argument is for a commit or branch
<<<<<<< HEAD
-u|--url	Specify the URL of the repository. Default is https://github.com/Actinium-project/Actinium
=======
-u|--url	Specify the URL of the repository. Default is https://github.com/litecoin-project/litecoin
>>>>>>> upstream/0.16
-v|--verify 	Verify the gitian build
-b|--build	Do a gitian build
-s|--sign	Make signed binaries for Windows and Mac OSX
-B|--buildsign	Build both signed and unsigned binaries
-o|--os		Specify which Operating Systems the build is for. Default is lwx. l for linux, w for windows, x for osx
-j		Number of processes to use. Default 2
-m		Memory to allocate in MiB. Default 2000
--kvm           Use KVM instead of LXC
<<<<<<< HEAD
--setup         Setup the gitian building environment. Uses KVM. If you want to use lxc, use the --lxc option. Only works on Debian-based systems (Ubuntu, Debian)
=======
--setup         Set up the Gitian building environment. Uses KVM. If you want to use lxc, use the --lxc option. Only works on Debian-based systems (Ubuntu, Debian)
>>>>>>> upstream/0.16
--detach-sign   Create the assert file for detached signing. Will not commit anything.
--no-commit     Do not commit anything to git
-h|--help	Print this help message
EOF

# Get options and arguments
while :; do
    case $1 in
        # Verify
        -v|--verify)
	    verify=true
            ;;
        # Build
        -b|--build)
	    build=true
            ;;
        # Sign binaries
        -s|--sign)
	    sign=true
            ;;
        # Build then Sign
        -B|--buildsign)
	    sign=true
	    build=true
            ;;
        # PGP Signer
        -S|--signer)
	    if [ -n "$2" ]
	    then
		SIGNER=$2
		shift
	    else
		echo 'Error: "--signer" requires a non-empty argument.'
		exit 1
	    fi
           ;;
        # Operating Systems
        -o|--os)
	    if [ -n "$2" ]
	    then
		linux=false
		windows=false
		osx=false
		if [[ "$2" = *"l"* ]]
		then
		    linux=true
		fi
		if [[ "$2" = *"w"* ]]
		then
		    windows=true
		fi
		if [[ "$2" = *"x"* ]]
		then
		    osx=true
		fi
		shift
	    else
<<<<<<< HEAD
		echo 'Error: "--os" requires an argument containing an l (for linux), w (for windows), or x (for Mac OSX)\n'
=======
		echo 'Error: "--os" requires an argument containing an l (for linux), w (for windows), or x (for Mac OSX)'
>>>>>>> upstream/0.16
		exit 1
	    fi
	    ;;
	# Help message
	-h|--help)
	    echo "$usage"
	    exit 0
	    ;;
	# Commit or branch
	-c|--commit)
	    commit=true
	    ;;
	# Number of Processes
	-j)
	    if [ -n "$2" ]
	    then
		proc=$2
		shift
	    else
		echo 'Error: "-j" requires an argument'
		exit 1
	    fi
	    ;;
	# Memory to allocate
	-m)
	    if [ -n "$2" ]
	    then
		mem=$2
		shift
	    else
		echo 'Error: "-m" requires an argument'
		exit 1
	    fi
	    ;;
	# URL
	-u)
	    if [ -n "$2" ]
	    then
		url=$2
		shift
	    else
		echo 'Error: "-u" requires an argument'
		exit 1
	    fi
	    ;;
        # kvm
        --kvm)
            lxc=false
            ;;
        # Detach sign
        --detach-sign)
            signProg="true"
            commitFiles=false
            ;;
        # Commit files
        --no-commit)
            commitFiles=false
            ;;
        # Setup
        --setup)
            setup=true
            ;;
	*)               # Default case: If no more options then break out of the loop.
             break
    esac
    shift
done

# Set up LXC
if [[ $lxc = true ]]
then
    export USE_LXC=1
<<<<<<< HEAD
    export LXC_BRIDGE=lxcbr0
    sudo ifconfig lxcbr0 up 10.0.2.2
=======
>>>>>>> upstream/0.16
fi

# Check for OSX SDK
if [[ ! -e "gitian-builder/inputs/MacOSX10.11.sdk.tar.gz" && $osx == true ]]
then
    echo "Cannot build for OSX, SDK does not exist. Will build for other OSes"
    osx=false
fi

# Get signer
<<<<<<< HEAD
if [[ -n"$1" ]]
=======
if [[ -n "$1" ]]
>>>>>>> upstream/0.16
then
    SIGNER=$1
    shift
fi

# Get version
if [[ -n "$1" ]]
then
    VERSION=$1
    COMMIT=$VERSION
    shift
fi

# Check that a signer is specified
if [[ $SIGNER == "" ]]
then
    echo "$scriptName: Missing signer."
    echo "Try $scriptName --help for more information"
    exit 1
fi

# Check that a version is specified
if [[ $VERSION == "" ]]
then
    echo "$scriptName: Missing version."
    echo "Try $scriptName --help for more information"
    exit 1
fi

# Add a "v" if no -c
if [[ $commit = false ]]
then
	COMMIT="v${VERSION}"
fi
echo ${COMMIT}

# Setup build environment
if [[ $setup = true ]]
then
    sudo apt-get install ruby apache2 git apt-cacher-ng python-vm-builder qemu-kvm qemu-utils
<<<<<<< HEAD
    git clone https://github.com/Actinium-project/gitian.sigs.ltc.git
    git clone https://github.com/Actinium-project/Actinium-detached-sigs.git
=======
    git clone https://github.com/litecoin-project/gitian.sigs.ltc.git
    git clone https://github.com/litecoin-project/litecoin-detached-sigs.git
>>>>>>> upstream/0.16
    git clone https://github.com/devrandom/gitian-builder.git
    pushd ./gitian-builder
    if [[ -n "$USE_LXC" ]]
    then
        sudo apt-get install lxc
        bin/make-base-vm --suite trusty --arch amd64 --lxc
    else
        bin/make-base-vm --suite trusty --arch amd64
    fi
    popd
fi

# Set up build
<<<<<<< HEAD
pushd ./Actinium
=======
pushd ./litecoin
>>>>>>> upstream/0.16
git fetch
git checkout ${COMMIT}
popd

# Build
if [[ $build = true ]]
then
	# Make output folder
<<<<<<< HEAD
	mkdir -p ./Actinium-binaries/${VERSION}
=======
	mkdir -p ./litecoin-binaries/${VERSION}
>>>>>>> upstream/0.16
	
	# Build Dependencies
	echo ""
	echo "Building Dependencies"
	echo ""
	pushd ./gitian-builder	
	mkdir -p inputs
	wget -N -P inputs $osslPatchUrl
	wget -N -P inputs $osslTarUrl
<<<<<<< HEAD
	make -C ../Actinium/depends download SOURCES_PATH=`pwd`/cache/common
=======
	make -C ../litecoin/depends download SOURCES_PATH=`pwd`/cache/common
>>>>>>> upstream/0.16

	# Linux
	if [[ $linux = true ]]
	then
            echo ""
	    echo "Compiling ${VERSION} Linux"
	    echo ""
<<<<<<< HEAD
	    ./bin/gbuild -j ${proc} -m ${mem} --commit Actinium=${COMMIT} --url Actinium=${url} ../Actinium/contrib/gitian-descriptors/gitian-linux.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-linux --destination ../gitian.sigs.ltc/ ../Actinium/contrib/gitian-descriptors/gitian-linux.yml
	    mv build/out/Actinium-*.tar.gz build/out/src/Actinium-*.tar.gz ../Actinium-binaries/${VERSION}
=======
	    ./bin/gbuild -j ${proc} -m ${mem} --commit litecoin=${COMMIT} --url litecoin=${url} ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-linux --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
	    mv build/out/litecoin-*.tar.gz build/out/src/litecoin-*.tar.gz ../litecoin-binaries/${VERSION}
>>>>>>> upstream/0.16
	fi
	# Windows
	if [[ $windows = true ]]
	then
	    echo ""
	    echo "Compiling ${VERSION} Windows"
	    echo ""
<<<<<<< HEAD
	    ./bin/gbuild -j ${proc} -m ${mem} --commit Actinium=${COMMIT} --url Actinium=${url} ../Actinium/contrib/gitian-descriptors/gitian-win.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-win-unsigned --destination ../gitian.sigs.ltc/ ../Actinium/contrib/gitian-descriptors/gitian-win.yml
	    mv build/out/Actinium-*-win-unsigned.tar.gz inputs/Actinium-win-unsigned.tar.gz
	    mv build/out/Actinium-*.zip build/out/Actinium-*.exe ../Actinium-binaries/${VERSION}
=======
	    ./bin/gbuild -j ${proc} -m ${mem} --commit litecoin=${COMMIT} --url litecoin=${url} ../litecoin/contrib/gitian-descriptors/gitian-win.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-win-unsigned --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-win.yml
	    mv build/out/litecoin-*-win-unsigned.tar.gz inputs/litecoin-win-unsigned.tar.gz
	    mv build/out/litecoin-*.zip build/out/litecoin-*.exe ../litecoin-binaries/${VERSION}
>>>>>>> upstream/0.16
	fi
	# Mac OSX
	if [[ $osx = true ]]
	then
	    echo ""
	    echo "Compiling ${VERSION} Mac OSX"
	    echo ""
<<<<<<< HEAD
	    ./bin/gbuild -j ${proc} -m ${mem} --commit Actinium=${COMMIT} --url Actinium=${url} ../Actinium/contrib/gitian-descriptors/gitian-osx.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-osx-unsigned --destination ../gitian.sigs.ltc/ ../Actinium/contrib/gitian-descriptors/gitian-osx.yml
	    mv build/out/Actinium-*-osx-unsigned.tar.gz inputs/Actinium-osx-unsigned.tar.gz
	    mv build/out/Actinium-*.tar.gz build/out/Actinium-*.dmg ../Actinium-binaries/${VERSION}
=======
	    ./bin/gbuild -j ${proc} -m ${mem} --commit litecoin=${COMMIT} --url litecoin=${url} ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-osx-unsigned --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
	    mv build/out/litecoin-*-osx-unsigned.tar.gz inputs/litecoin-osx-unsigned.tar.gz
	    mv build/out/litecoin-*.tar.gz build/out/litecoin-*.dmg ../litecoin-binaries/${VERSION}
>>>>>>> upstream/0.16
	fi
	popd

        if [[ $commitFiles = true ]]
        then
	    # Commit to gitian.sigs repo
            echo ""
            echo "Committing ${VERSION} Unsigned Sigs"
            echo ""
            pushd gitian.sigs
            git add ${VERSION}-linux/${SIGNER}
            git add ${VERSION}-win-unsigned/${SIGNER}
            git add ${VERSION}-osx-unsigned/${SIGNER}
            git commit -a -m "Add ${VERSION} unsigned sigs for ${SIGNER}"
            popd
        fi
fi

# Verify the build
if [[ $verify = true ]]
then
	# Linux
	pushd ./gitian-builder
	echo ""
	echo "Verifying v${VERSION} Linux"
	echo ""
<<<<<<< HEAD
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-linux ../Actinium/contrib/gitian-descriptors/gitian-linux.yml
=======
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-linux ../litecoin/contrib/gitian-descriptors/gitian-linux.yml
>>>>>>> upstream/0.16
	# Windows
	echo ""
	echo "Verifying v${VERSION} Windows"
	echo ""
<<<<<<< HEAD
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-win-unsigned ../Actinium/contrib/gitian-descriptors/gitian-win.yml
=======
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-win-unsigned ../litecoin/contrib/gitian-descriptors/gitian-win.yml
>>>>>>> upstream/0.16
	# Mac OSX	
	echo ""
	echo "Verifying v${VERSION} Mac OSX"
	echo ""	
<<<<<<< HEAD
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-unsigned ../Actinium/contrib/gitian-descriptors/gitian-osx.yml
=======
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-unsigned ../litecoin/contrib/gitian-descriptors/gitian-osx.yml
>>>>>>> upstream/0.16
	# Signed Windows
	echo ""
	echo "Verifying v${VERSION} Signed Windows"
	echo ""
<<<<<<< HEAD
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-signed ../Actinium/contrib/gitian-descriptors/gitian-osx-signer.yml
=======
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-signed ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
>>>>>>> upstream/0.16
	# Signed Mac OSX
	echo ""
	echo "Verifying v${VERSION} Signed Mac OSX"
	echo ""
<<<<<<< HEAD
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-signed ../Actinium/contrib/gitian-descriptors/gitian-osx-signer.yml	
=======
	./bin/gverify -v -d ../gitian.sigs.ltc/ -r ${VERSION}-osx-signed ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml	
>>>>>>> upstream/0.16
	popd
fi

# Sign binaries
if [[ $sign = true ]]
then
	
        pushd ./gitian-builder
	# Sign Windows
	if [[ $windows = true ]]
	then
	    echo ""
	    echo "Signing ${VERSION} Windows"
	    echo ""
<<<<<<< HEAD
	    ./bin/gbuild -i --commit signature=${COMMIT} ../Actinium/contrib/gitian-descriptors/gitian-win-signer.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-win-signed --destination ../gitian.sigs.ltc/ ../Actinium/contrib/gitian-descriptors/gitian-win-signer.yml
	    mv build/out/Actinium-*win64-setup.exe ../Actinium-binaries/${VERSION}
	    mv build/out/Actinium-*win32-setup.exe ../Actinium-binaries/${VERSION}
=======
	    ./bin/gbuild -i --commit signature=${COMMIT} ../litecoin/contrib/gitian-descriptors/gitian-win-signer.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-win-signed --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-win-signer.yml
	    mv build/out/litecoin-*win64-setup.exe ../litecoin-binaries/${VERSION}
	    mv build/out/litecoin-*win32-setup.exe ../litecoin-binaries/${VERSION}
>>>>>>> upstream/0.16
	fi
	# Sign Mac OSX
	if [[ $osx = true ]]
	then
	    echo ""
	    echo "Signing ${VERSION} Mac OSX"
	    echo ""
<<<<<<< HEAD
	    ./bin/gbuild -i --commit signature=${COMMIT} ../Actinium/contrib/gitian-descriptors/gitian-osx-signer.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-osx-signed --destination ../gitian.sigs.ltc/ ../Actinium/contrib/gitian-descriptors/gitian-osx-signer.yml
	    mv build/out/Actinium-osx-signed.dmg ../Actinium-binaries/${VERSION}/Actinium-${VERSION}-osx.dmg
=======
	    ./bin/gbuild -i --commit signature=${COMMIT} ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
	    ./bin/gsign -p $signProg --signer $SIGNER --release ${VERSION}-osx-signed --destination ../gitian.sigs.ltc/ ../litecoin/contrib/gitian-descriptors/gitian-osx-signer.yml
	    mv build/out/litecoin-osx-signed.dmg ../litecoin-binaries/${VERSION}/litecoin-${VERSION}-osx.dmg
>>>>>>> upstream/0.16
	fi
	popd

        if [[ $commitFiles = true ]]
        then
            # Commit Sigs
            pushd gitian.sigs
            echo ""
            echo "Committing ${VERSION} Signed Sigs"
            echo ""
            git add ${VERSION}-win-signed/${SIGNER}
            git add ${VERSION}-osx-signed/${SIGNER}
            git commit -a -m "Add ${VERSION} signed binary sigs for ${SIGNER}"
            popd
        fi
fi
