// MinIO C++ Library for Amazon S3 Compatible Cloud Storage
// Copyright 2022 MinIO, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "client.h"
#include <chrono>
#include <thread>

struct UploadToCloud {
  explicit UploadToCloud()
      : base_url("https://oss.deepblueyun.com:8043"),
        provider("L7NBFE6343JHFJ1T927G",
                 "QPOdio00bCbX8KBOwkOfl80a26unTDj4ksPPv4tu"),
        client(base_url, &provider) {
    // std::cout << "Upload to cloud, set to debug mode." << std::endl;
    client.Debug(true);
  }

  bool Exist() {
    minio::s3::BucketExistsArgs args;
    args.bucket = "athena";

    // client.Debug(true);
    minio::s3::BucketExistsResponse resp = client.BucketExists(args);

    // Handle response.
    if (resp) {
      if (resp.exist) {
        std::cout << "athena exists" << std::endl;
        return true;
      } else {
        // minio::s3::MakeBucketArgs make_args;
        // make_args.bucket = "athena";
        std::cout << "athena does not exist" << std::endl;
      }
    } else {
      std::cout << "unable to do bucket existence check; "
                << resp.Error().String() << std::endl;
    }
    return false;
  }

  void Upload() {
    minio::s3::UploadObjectArgs args;
    args.bucket = "athena";
    args.object = "wps-office_11.1.0.11698_amd64.deb";
    args.filename = "/home/xuyq/Downloads/" + args.object;

    minio::s3::UploadObjectResponse resp = client.UploadObject(args);

    // Handle response.
    if (resp) {
      std::cout << "wps-office_11.1.0.11698_amd64.deb is successfully uploaded to autonomous"
                << std::endl;
    } else {
      std::cout << "unable to upload wps-office_11.1.0.11698_amd64.deb; " << resp.Error().String()
                << std::endl;
    }
  }

void PrintUploadProgress(bool& run_flag)
{
  while (run_flag)
  {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "PrintUploadProgress->upload progress: " << client.GetUploadProgress() << "%" << std::endl;
  }
}


private:
  // Create S3 base URL.
  minio::s3::BaseUrl base_url;

  // Create credential provider.
  minio::creds::StaticProvider provider;

  // Create S3 client.
  minio::s3::Client client;
};

int main(int argc, char *argv[]) {

  UploadToCloud upload_to_cloud;
  bool run_flag = true;
  if (upload_to_cloud.Exist())
  {
    std::thread t1(&UploadToCloud::PrintUploadProgress, upload_to_cloud, std::ref(run_flag));
    // upload_to_cloud.GetProgress(run_flag);
    upload_to_cloud.Upload();
    run_flag = false;
    t1.join();
  }
    
  return 0;
}
