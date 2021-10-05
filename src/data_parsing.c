/*
 * Author   : Noh, Ki-Hyeon
 * Filename : data_parsing.c
 * Release  : 
 * Date     : 
 *
 * Description : Json Data Parsing Structure
 *
 * Notes :
 * ===================
 * History
 * ===================
 *
 */

#include "include.h"

/*
 * Parse text into a JSON object. If text is valid JSON, returns a
 * json_t structure, otherwise prints and error and returns null.
 */

json_t *load_json(const char *text) {
	json_t *root;
	json_error_t error;

	root = json_loads(text, 0, &error);

	if (root) {
		return root;
	} else {
		fprintf(stderr, "json error on line %d: %s\n", error.line, error.text);
		return (json_t *)0;
	}
}

int dataParsing(char* data){
	json_t *root;
	char* afterData;

	size_t index;
	json_t *array_value;
	const char *key;
	json_t *value;
	const char *same_nameKey;
	json_t *same_nameValue;

	afterData = strstr(data, "{");
	if(afterData == NULL)
		error_handling("문자열을 찾을 수 없습니다.");

	/* parse json Text*/
	root = load_json(afterData);

	json_t *jsonData = json_object_get(root, "documents");
	json_array_foreach(jsonData, index, array_value){ 
		if(json_typeof(array_value) == JSON_OBJECT){
			json_object_foreach(array_value, key, value){
				if(strstr(key, "address_name"))
					strcpy(dataSet.documents[index].address_name , json_string_value(value));
				else if(strstr(key, "category_group_code"))
					strcpy(dataSet.documents[index].category_group_code , json_string_value(value));
				else if(strstr(key, "category_group_name"))
					strcpy(dataSet.documents[index].category_group_name , json_string_value(value));
				else if(strstr(key, "category_name"))
					strcpy(dataSet.documents[index].category_name , json_string_value(value));
				else if(strstr(key, "distance"))
					strcpy(dataSet.documents[index].distance , json_string_value(value));
				else if(strstr(key, "id"))
					strcpy(dataSet.documents[index].id , json_string_value(value));
				else if(strstr(key, "phone"))
					strcpy(dataSet.documents[index].phone , json_string_value(value));
				else if(strstr(key, "place_name"))
					strcpy(dataSet.documents[index].place_name , json_string_value(value));
				else if(strstr(key, "place_url"))
					strcpy(dataSet.documents[index].place_url , json_string_value(value));
				else if(strstr(key, "road_address_name"))
					strcpy(dataSet.documents[index].road_address_name  , json_string_value(value));
				else if(strstr(key,"x"))
					strcpy(dataSet.documents[index].x , json_string_value(value));
				else if(strstr(key,"y"))
					strcpy(dataSet.documents[index].y , json_string_value(value));
				else
					error_handling("not found structure");
			}
		}
		else
			error_handling("Not Found Object\n");

		printf("\naddress_name = %s\ncategory_group_code = %s\ncategory_group_name = %s\ncategory_name = %s\ndistance = %s\nid = %s\nphone = %s\nplace_name = %s\nplace_url = %s\nroad_address_name = %s\nx=%s\ny=%s\n\n\n", dataSet.documents[index].address_name, dataSet.documents[index].category_group_code, dataSet.documents[index].category_group_name, dataSet.documents[index].category_name, dataSet.documents[index].distance, dataSet.documents[index].id,dataSet.documents[index].phone, dataSet.documents[index].place_name, dataSet.documents[index].place_url,dataSet.documents[index].road_address_name,dataSet.documents[index].x, dataSet.documents[index].y);
	}

	jsonData = json_object_get(root, "meta");
	json_object_foreach(jsonData, key, value){
		if(strstr(key, "is_end"))
			dataSet.meta.is_end = json_boolean_value(value);
		else if(strstr(key, "pageable_count"))
			dataSet.meta.pageable_count = json_integer_value(value);
		else if(strstr(key, "same_name")){
			json_t *jsonSameName = json_object_get(jsonData, "same_name");
			json_object_foreach(jsonSameName, same_nameKey, same_nameValue){

				if(json_typeof(value) == JSON_OBJECT){
					if(strstr(same_nameKey, "keyword"))
						strcpy(dataSet.meta.same_name.keyword , json_string_value(same_nameValue));
					else if(strstr(same_nameKey, "region"))
						continue;
					else if(strstr(same_nameKey, "selected_region"))
						strcpy(dataSet.meta.same_name.selected_region , json_string_value(same_nameValue));
					else
						error_handling("Not Found: same_name\n");
				}
				else
					error_handling("Not Found : same_name Object\n");
			}
			//dataSet.meta.pageable_count = json_integer_value(value);
		}
		else if(strstr(key, "total_count"))
			dataSet.meta.total_count= json_integer_value(value);
		else
			error_handling("Not Found meta\n");
	}

	printf("Meta\nis_end = %d\npageable_count = %d\ntotal_count = %d\n",dataSet.meta.is_end, dataSet.meta.pageable_count, dataSet.meta.total_count);
	printf("\nsame_name\nkeyword = %s\n\nselected_region = %s\n", dataSet.meta.same_name.keyword, dataSet.meta.same_name.selected_region);

	return 0;
}
