/**
 * GStreamer Tensor_Filter, Tensorflow-Lite Module
 * Copyright (C) 2018 MyungJoo Ham <myungjoo.ham@samsung.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * @file	tensor_filter_tensorflow_lite.c
 * @date	24 May 2018
 * @brief	Tensorflow-lite module for tensor_filter gstreamer plugin
 * @see		http://github.com/TO-BE-DETERMINED-SOON
 * @see		https://github.sec.samsung.net/STAR/nnstreamer
 * @author	MyungJoo Ham <myungjoo.ham@samsung.com>
 *
 * This is the per-NN-framework plugin (tensorflow-lite) for tensor_filter.
 * Fill in "GstTensor_Filter_Framework" for tensor_filter.h/c
 *
 */

#include "tensor_filter.h"

/**
 * @brief Load tensorflow lite modelfile
 * @return 0 if successfully loaded. 1 if skipped (already loaded). -1 if error
 */
static int
tflite_loadModelFile (const GstTensor_Filter * filter, void **private_data)
{
  /* @TODO need to decide wheter make internal data structure or not
   * need to add skip logic when model file already loaded
   * need to load tensorflow lite model file by FlatBufferModel::BuildFromFile
   * after configuration of c->cpp api of tflite works done
   */
  return 0;
}

/**
 * @brief The mandatory callback for GstTensor_Filter_Framework
 */
static int
tflite_invoke (const GstTensor_Filter * filter, void **private_data,
    const uint8_t * inptr, uint8_t * outptr)
{
  return 0;                     /* NYI */
}

/**
 * @brief The optional callback for GstTensor_Filter_Framework
 */
static int
tflite_getInputDim (const GstTensor_Filter * filter, void **private_data,
    tensor_dim inputDimension, tensor_type * type)
{
  int retval = tflite_loadModelFile (filter, private_data);
  /* @TODO fill in *inputDimension (uint32_t[MAX_RANK]), *type */

  return retval;                // NYI
}

/**
 * @brief The optional callback for GstTensor_Filter_Framework
 */
static int
tflite_getOutputDim (const GstTensor_Filter * filter, void **private_data,
    tensor_dim outputDimension, tensor_type * type)
{
  int retval = tflite_loadModelFile (filter, private_data);
  /* @TODO fill in *outputDimension (uint32_t[MAX_RANK]), *type */

  return retval;                /* NYI */
}

GstTensor_Filter_Framework NNS_support_tensorflow_lite = {
  .name = "tensorflow-lite",
  .allow_in_place = FALSE,      /* Let's not do this yet. @TODO: support this to optimize performance later. */
  .invoke_NN = tflite_invoke,
  .getInputDimension = tflite_getInputDim,
  .getOutputDimension = tflite_getOutputDim,
};
