// HW01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
// 필수 
// 1. 5개 숫자 입력받아 배열에 저장
// 2. 배열의 합계와 평균 계산
// * 배열 합계 반환 함수 구현
// * 배열 평균 반환 함수 구현
// 3. 위 함수 호출하여 합계와 평균 출력 

// 도전
// 숫자 1 입력 받으면 오름차순 2는 내림차순 정렬
// 각각 함수로 구현
// * sort 사용 금지

// 배열의 총합
double arrSum(double arr[], int arrSize) {
	double result = 0;
	for (int i = 0; i < arrSize; i++) {
		result += arr[i];
	}
	return result;
}
// 배열의 평균
double arrAvg(double arr[], int arrSize) {
	return arrSum(arr,arrSize)/arrSize;
}

// 배열 오름차순 정렬 1,2,3,4,5
void arrAscending(double arr[], double arrSort[], int arrSize) {
	int j = 0;
	while (j < arrSize) {

		double minNum;
		bool isSet = false;

		//최소값 구하기
		for (int i = 0; i < arrSize; i++) {
			bool isUsed = false;
			// 이미 정렬된 값인지 확인
			for (int k = 0; k < j; k++) {
				if (arrSort[k] == arr[i]) {
					isUsed = true;
					break;
				}
			}
			if (!isUsed) {
				if (!isSet) {
					minNum = arr[i];
					isSet = true;
				}
				else if (arr[i] < minNum) {
					minNum = arr[i];
				}	
			}
		}

		// 중복인 숫자 배열에 넣기
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == minNum) {
				arrSort[j] = minNum;
				j++;
			}
		}
	}

	cout << "오름차순 정렬: ";
	for (int i = 0; i < arrSize; i++) {
		cout << arrSort[i] << " ";
	}

}

// 배열 내림차순 정렬 5,4,3,2,1
void arrDescending(double arr[], double arrSort[], int arrSize) {
	int j = 0;
	while (j < arrSize) {

		double maxNum;
		bool isSet = false;

		//최대값 구하기
		for (int i = 0; i < arrSize; i++) {
			bool isUsed = false;
			// 이미 정렬된 값인지 확인
			for (int k = 0; k < j; k++) {
				if (arrSort[k] == arr[i]) {
					isUsed = true;
					break;
				}
			}
			if (!isUsed) {
				if (!isSet) {
					maxNum = arr[i];
					isSet = true;
				}
				else if (arr[i] > maxNum) {
					maxNum = arr[i];
				}
			}
		}

		// 중복인 숫자 배열에 넣기
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == maxNum) {
				arrSort[j] = maxNum;
				j++;
			}
		}
	}
	cout << "내림차순 정렬: ";
	for (int i = 0; i < arrSize; i++) {
		cout << arrSort[i] << " ";
	}
}

int main()
{ 
	double arr[5];
	double arrSort1[sizeof(arr) / sizeof(double)];
	double arrSort2[sizeof(arr) / sizeof(double)];
	int sortNum = 0;

	// 배열에 입력 받기
	for (int i = 0; i < sizeof(arr) / sizeof(double); i++) {
		cout << i + 1 << "번째 숫자 입력: ";
		cin >> arr[i];
	}

	cout << "총합: " << arrSum(arr, sizeof(arr) / sizeof(double)) << endl;
	cout << "평균: " << arrAvg(arr, sizeof(arr) / sizeof(double)) << endl;

	cout << "입력한 배열 정렬(1: 오름차순, 2: 내림차순): ";
	while (1) {
		cin >> sortNum;
		if (sortNum != 1 && sortNum != 2) {
			cout << "잘못된 입력. 다시 입력해주세요: ";
		}
		else {
			break;
		}
	}
	if (sortNum == 1) {
		arrAscending(arr, arrSort1, sizeof(arr) / sizeof(double));
	}
	else {
		arrDescending(arr, arrSort2, sizeof(arr) / sizeof(double));
	}

}


