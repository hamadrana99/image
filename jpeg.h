#ifndef TH_JPEG_INC
#define TH_JPEG_INC
#include <TH.h>
#include <jpeglib.h>
#include <setjmp.h>

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_Tensor TH_CONCAT_STRING_3(torch., Real, Tensor)
#define libjpeg_(NAME) TH_CONCAT_3(libjpeg_, Real, NAME)

static void
jpeg_mem_src_dummy(j_decompress_ptr c, unsigned char *ibuf, unsigned long isiz);
static void
jpeg_mem_dest_dummy(j_compress_ptr c, unsigned char **obuf, unsigned long *osiz);

#define JPEG_MEM_SRC_NOT_DEF  "`jpeg_mem_src` is not defined."
#define JPEG_MEM_DEST_NOT_DEF "`jpeg_mem_dest` is not defined."
#define JPEG_REQUIRED_VERSION " Use libjpeg v8+, libjpeg-turbo 1.3+ or build" \
                              " libjpeg-turbo with `--with-mem-srcdst`."

#define JPEG_MEM_SRC_ERR_MSG  JPEG_MEM_SRC_NOT_DEF JPEG_REQUIRED_VERSION
#define JPEG_MEM_DEST_ERR_MSG JPEG_MEM_DEST_NOT_DEF JPEG_REQUIRED_VERSION

#if !defined(HAVE_JPEG_MEM_SRC)
#define jpeg_mem_src jpeg_mem_src_dummy
#endif

#if !defined(HAVE_JPEG_MEM_DEST)
#define jpeg_mem_dest jpeg_mem_dest_dummy
#endif

#include "generic/jpeg.h"
#include "THGenerateAllTypes.h"
#endif

