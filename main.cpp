#include <chrono>
#include <format>
#include <iostream>

int main()
{
	const std::chrono::time_point days_now{ std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()) };

	const std::chrono::year_month_day ymd{ days_now };

	std::cout << "Today is " << std::format("{:%B}", ymd) << ' ' << std::format("{:%d}", ymd) << ", " << std::format("{:%Y}", ymd) << '\n';
	std::cout << '\n';

	return 0;
}