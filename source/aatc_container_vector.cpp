/*
The zlib/libpng License
http://opensource.org/licenses/zlib-license.php


Angelscript addon Template Containers
Copyright (c) 2014 Sami Vuorela

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it freely,
subject to the following restrictions:

1.	The origin of this software must not be misrepresented;
You must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2.	Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3.	This notice may not be removed or altered from any source distribution.


Sami Vuorela
samivuorela@gmail.com
*/



#include "aatc_container_vector.hpp"

#include "aatc_container_listing.hpp"
#include "aatc_container_templated_shared_method.hpp"



BEGIN_AS_NAMESPACE
namespace aatc {
	namespace container {
		namespace listing {



			const char* container::listing::tags_of_container::vector::scriptname_container = config::scriptname::container::vector;



		}//namespace listing
		namespace templated {



			vector::vector(asIObjectType* _objtype) :
				Containerbase(_objtype->GetEngine(), _objtype)
			{}
			vector::vector(const vector& other) :
				Containerbase(other.engine, other.objtype_container)
			{
				(*this) = other;
			}
			vector& vector::operator=(const vector& other) { Containerbase::operator=(other); return *this; }

			vector& vector::swap(vector& other) {
				shared::method::swap(this, other);
				return *this;
			}

			void vector::push_back(void* value) { shared::method::native::push_back(this, value); }
			void vector::pop_back() { shared::method::native::pop_back(this); }
			void* vector::back() { return shared::method::native::back(this); }
			void* vector::front() { return shared::method::native::front(this); }

			void* vector::operator[](config::t::sizetype position) { return shared::method::native::operator_index_position(this, position); }

			void vector::sort(bool ascending) { shared::method::genericcc::sort(this, ascending); }
			void vector::sort_funcptr(common::aatc_script_Funcpointer* funcptr, bool ascending) { shared::method::genericcc::sort_funcptr(this,funcptr, ascending); }

			void vector::erase(config::t::sizetype position) { shared::method::genericcc::erase_position_constant(this, position); }
			void vector::erase(const Iterator& position) { shared::method::native::erase_iterator(this, position); }
			config::t::sizetype vector::erase(config::t::sizetype range_begin, config::t::sizetype range_end) { return shared::method::genericcc::erase_position_range_constant(this, range_begin, range_end); }
			config::t::sizetype vector::erase(const Iterator& range_begin, const Iterator& range_end) { return shared::method::native::erase_iterator_range(this, range_begin, range_end); }

			config::t::sizetype vector::erase_value(void* value, bool all) { return shared::method::genericcc::erase_value(this, value, all); }

			vector::Iterator vector::find(void* value) { return shared::method::genericcc::find_iterator(this, value); }

			void vector::insert(const Iterator& position, void* value) { shared::method::native::insert_iterator(this, position, value); }



		};//namespace templated
		namespace listing {



			template<> void register_container<CONTAINER::VECTOR>(asIScriptEngine* engine) {
				common::RegistrationState rs(engine);

				{
					using templated::vector;
					using namespace templated::shared;

					register_containerbase<vector>(rs);



					register_method::swap<vector>(rs);

					register_method::native::push_back<vector>(rs);
					register_method::native::pop_back<vector>(rs);

					register_method::native::back<vector>(rs);
					register_method::native::front<vector>(rs);

					register_method::native::operator_index_position<vector>(rs);

					register_method::genericcc::sort<vector>(rs);

					register_method::native::erase_iterator<vector>(rs);
					register_method::genericcc::erase_position_constant<vector>(rs);
					register_method::native::erase_iterator_range<vector>(rs);
					register_method::genericcc::erase_position_range_constant<vector>(rs);

					register_method::genericcc::erase_value<vector>(rs);

					register_method::genericcc::find_iterator<vector>(rs);

					register_method::native::insert_iterator<vector>(rs);
				}

				container::shared::autoregister::register_all_tempspec_basics_for_container<tempspec::vector>(engine);
			}
			template<> common::container_operations_bitmask_type errorcheck_missing_functions_make_bitfield_for_template<CONTAINER::VECTOR>(enginestorage::template_specific_storage* tss) {
				common::container_operations_bitmask_type mask = 0;
				
				if (!tss->func_cmp) {
					mask |= common::CONTAINER_OPERATION::SORT;
				}
				if (!tss->func_equals) {
					mask |= common::CONTAINER_OPERATION::COUNT;
				}
				
				return mask;
			}



		};//namespace listing



	};//namespace container
};//namespace aatc

END_AS_NAMESPACE