#pragma once

#include <vector>
#include "../Province/Province.hh"

namespace PA
{
	namespace Country
	{
		class Country
		{
		public:
			Country();

			void add_province(PA::Province::Province* province);

		private:
			std::vector<PA::Province::Province*> provinces;
		};
	}
}
