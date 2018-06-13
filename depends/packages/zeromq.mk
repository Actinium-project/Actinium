package=zeromq
<<<<<<< HEAD
$(package)_version=4.1.5
$(package)_download_path=https://github.com/zeromq/zeromq4-1/releases/download/v$($(package)_version)/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=04aac57f081ffa3a2ee5ed04887be9e205df3a7ddade0027460b8042432bdbcf
$(package)_patches=9114d3957725acd34aa8b8d011585812f3369411.patch 9e6745c12e0b100cd38acecc16ce7db02905e27c.patch

define $(package)_set_vars
  $(package)_config_opts=--without-documentation --disable-shared --without-libsodium --disable-curve
=======
$(package)_version=4.2.2
$(package)_download_path=https://github.com/zeromq/libzmq/releases/download/v$($(package)_version)/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=5b23f4ca9ef545d5bd3af55d305765e3ee06b986263b31967435d285a3e6df6b
$(package)_patches=0001-fix-build-with-older-mingw64.patch

define $(package)_set_vars
  $(package)_config_opts=--without-docs --disable-shared --without-libsodium --disable-curve --disable-curve-keygen --disable-perf
>>>>>>> upstream/0.16
  $(package)_config_opts_linux=--with-pic
  $(package)_cxxflags=-std=c++11
endef

define $(package)_preprocess_cmds
<<<<<<< HEAD
  patch -p1 < $($(package)_patch_dir)/9114d3957725acd34aa8b8d011585812f3369411.patch && \
  patch -p1 < $($(package)_patch_dir)/9e6745c12e0b100cd38acecc16ce7db02905e27c.patch && \
=======
   patch -p1 < $($(package)_patch_dir)/0001-fix-build-with-older-mingw64.patch && \
>>>>>>> upstream/0.16
  ./autogen.sh
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
<<<<<<< HEAD
  $(MAKE) libzmq.la
=======
  $(MAKE) src/libzmq.la
>>>>>>> upstream/0.16
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install-libLTLIBRARIES install-includeHEADERS install-pkgconfigDATA
endef

define $(package)_postprocess_cmds
<<<<<<< HEAD
=======
  sed -i.old "s/ -lstdc++//" lib/pkgconfig/libzmq.pc && \
>>>>>>> upstream/0.16
  rm -rf bin share
endef
