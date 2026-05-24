#include <curl/curl.h>
#include <iostream>
#include <string>
#include <cctype>

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* str = static_cast<std::string*>(userp);
    str->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: taf <ICAO>\n";
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    std::string icao = argv[1];
    for (auto& c : icao) c = toupper(c);

    std::string url =
        "https://aviationweather.gov/api/data/taf?ids=" +
        icao + "&format=raw";

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to init curl\n";
        return 1;
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "CXX-TAF-Client/1.0");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        std::cerr << "curl error: " << curl_easy_strerror(res) << "\n";
    } else {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if (http_code == 200) {
            std::cout << response << "\n";
        } else {
            std::cerr << "HTTP error: " << http_code << "\n";
            std::cerr << response << "\n";
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
