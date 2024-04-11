#include <cstdlib>
#include <chrono>
#include <filesystem>
#include <format>
#include <iostream>
#include <string>

int main()
{
	char* username{};
	std::size_t username_size{};

	const errno_t err{ _dupenv_s(&username, &username_size, "USERPROFILE") };

	if (err)
	{
		std::cout << "Couldn't fetch USERPROFILE VARIABLE\n";
	}
	else
	{
		std::filesystem::path journal_path{ username };
		journal_path /= "Documents/anchor"; //apparently filesystem::path has a /= operator that appends

		if (!std::filesystem::exists(journal_path))
		{
			std::filesystem::create_directory(journal_path);
			std::cout << "Created\n";
		}
		else
		{
			std::cout << "Already exists\n";
		}
	}

	free(username); //_dupen_s uses malloc



	const std::chrono::time_point days_now{ std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()) };

	const std::chrono::year_month_day ymd{ days_now };

	std::cout << "Today is " << std::format("{:%B}", ymd) << ' ' << std::format("{:%d}", ymd) << ", " << std::format("{:%Y}", ymd) << '\n';
	std::cout << '\n';

	return 0;
}