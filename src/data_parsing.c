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
	int i;
	json_t *root;
	char* afterData;

	size_t index;
	json_t *array_value;
	const char *key;
	json_t *value;

	afterData = strstr(data, "{");
	if(afterData == NULL)
		error_handling("문자열을 찾을 수 없습니다.");

	/* parse json Text*/
	root = load_json(afterData);

	json_t *jsonData = json_object_get(root, "documents");
	json_array_foreach(jsonData, index, array_value){ 
		json_object_foreach(array_value, key, value){
			if(strstr(key, "address_name"))
				strcpy(dataSet.documents[i].address_name , json_string_value(value));
			else if(strcpy(key, "category_group_code"))
				strstr(dataSet.documents[i].category_group_code , json_string_value(value));
			else if(strcpy(key, "category_group_name"))
				strstr(dataSet.documents[i].category_group_name , json_string_value(value));
			else if(strcpy(key, "category_name"))
				strstr(dataSet.documents[i].category_name , json_string_value(value));
			else if(strcpy(key, "distance"))
				strstr(dataSet.documents[i].distance , json_string_value(value));
			else if(strcpy(key, "id"))
				strstr(dataSet.documents[i].id , json_string_value(value));
			else if(strcpy(key, "phone"))
				strstr(dataSet.documents[i].phone , json_string_value(value));
			else if(strcpy(key, "place_name"))
				strstr(dataSet.documents[i].place_name , json_string_value(value));
			else if(strcpy(key, "place_url"))
				strstr(dataSet.documents[i].place_url , json_string_value(value));
			else if(strcpy(key, "road_address_name"))
				strstr(dataSet.documents[i].road_address_name  , json_string_value(value));
			else if(strcpy(key,"x"))
				strstr(dataSet.documents[i].x , json_string_value(value));
			else if(strcpy(key,"y"))
				strstr(dataSet.documents[i].y , json_string_value(value));
			else
				error_handling("not found structure");
			//printf("%s : %s\n",key, json_string_value(value));
		}
		printf("\naddress_name = %s\ncategory_group_code = %s\ncategory_group_name = %s\ncategory_name = %s\ndistance = %s\nid = %s\nphone = %s\nplace_name = %s\nplace_url = %s\nroad_address_name = %s\nx=%s\ny=%s\n\n\n", dataSet.documents[i].address_name, dataSet.documents[i].category_group_code, dataSet.documents[i].category_group_name, dataSet.documents[i].category_name, dataSet.documents[i].distance, dataSet.documents[i].id,dataSet.documents[i].phone, dataSet.documents[i].place_name, dataSet.documents[i].place_url,dataSet.documents[i].road_address_name,dataSet.documents[i].x, dataSet.documents[i].y);
	}
	json_t *jsonMetaData = json_object_get(root, "meta");
	json_t *jsonIs_end = json_object_get(jsonMetaData, "is_end");
	dataSet.meta.is_end = json_boolean_value(jsonIs_end);
	json_t *jsonPageable_count = json_object_get(jsonMetaData, "pageable_count");
	dataSet.meta.pageable_count = json_integer_value(jsonPageable_count);
	json_t *jsonTotal_count = json_object_get(jsonMetaData, "total_count");
	dataSet.meta.total_count = json_integer_value(jsonTotal_count);
	printf("Meta\nis_end = %d\npageable_count = %d\ntotal_count = %d\n",dataSet.meta.is_end, dataSet.meta.pageable_count, dataSet.meta.total_count);

	json_t *jsonSame_name = json_object_get(jsonMetaData, "same_name");
	json_t *jsonKeyword = json_object_get(jsonSame_name, "keyword");
	strcpy(dataSet.meta.same_name.keyword , json_string_value(jsonKeyword));

	json_t *jsonSelected_region = json_object_get(jsonSame_name, "selected_region");
	strcpy(dataSet.meta.same_name.selected_region , json_string_value(jsonSelected_region));

	printf("\nsame_name\nkeyword = %s\n\nselected_region = %s\n", dataSet.meta.same_name.keyword, dataSet.meta.same_name.selected_region);

	return 0;
}
