// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2016 Intel Corporation. All Rights Reserved.

#pragma once
#include <thread>
#include <map>
#include "codec_interface.h"
#include "rs/record/record_device.h"

#ifdef WIN32 
#ifdef realsense_compression_EXPORTS
#define  DLL_EXPORT __declspec(dllexport)
#else
#define  DLL_EXPORT __declspec(dllimport)
#endif /* realsense_compression_EXPORTS */
#else /* defined (WIN32) */
#define DLL_EXPORT
#endif

namespace rs
{
    namespace core
    {
        namespace compression
        {
            class DLL_EXPORT lz4_codec : public codec_interface
            {
            public:
                lz4_codec();
                lz4_codec(record::compression_level compression_level);
                virtual ~lz4_codec();

                virtual status encode(file_types::frame_info &info, const uint8_t * input, uint8_t * output, uint32_t &output_size) override;
                virtual std::shared_ptr<file_types::frame_sample> decode(std::shared_ptr<file_types::frame_sample> frame, uint8_t * input, uint32_t input_size) override;
                virtual file_types::compression_type get_compression_type() override { return file_types::compression_type::lz4; }
            private:
                uint32_t m_compression_level;
            };
        }
    }
}
