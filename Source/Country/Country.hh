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

			std::vector<PA::Province::Province*> provinces;
		};
	}
}
