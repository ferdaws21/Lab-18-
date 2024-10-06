#include <iostream>
#include <string>

struct Review {
    float rating;
    std::string comment;
    Review* next;
};

class ReviewList {
private:
    Review* head;
    Review* tail;
    int count;

public:
    ReviewList() : head(nullptr), tail(nullptr), count(0) {}

    
    void addAtHead(float rating, const std::string& comment) {
        Review* newReview = new Review{rating, comment, head};
        head = newReview;
        if (tail == nullptr) {
            tail = head; 
        }
        count++;
    }

    
    void addAtTail(float rating, const std::string& comment) {
        Review* newReview = new Review{rating, comment, nullptr};
        if (tail != nullptr) {
            tail->next = newReview; 
        }
        tail = newReview; 
        if (head == nullptr) {
            head = tail; 
        }
        count++;
    }

    void outputReviews() const {
        Review* current = head;
        int index = 1;
        float total = 0.0;

        while (current != nullptr) {
            std::cout << "    > Review #" << index << ": " << current->rating << ": " << current->comment << std::endl;
            total += current->rating;
            current = current->next;
            index++;
        }

        if (count > 0) {
            std::cout << "    > Average: " << total / count << std::endl;
        } else {
            std::cout << "    > No reviews available." << std::endl;
        }
    }

    ~ReviewList() {
        Review* current = head;
        while (current != nullptr) {
            Review* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ReviewList reviews;
    int choice;

    std::cout << "Which linked list method should we use?" << std::endl;
    std::cout << "    [1] New nodes are added at the head of the linked list" << std::endl;
    std::cout << "    [2] New nodes are added at the tail of the linked list" << std::endl;
    std::cout << "    Choice: ";
    std::cin >> choice;

    char anotherReview = 'y';
    while (anotherReview == 'y' || anotherReview == 'Y') {
        float rating;
        std::string comment;

        std::cout << "Enter review rating 0-5: ";
        std::cin >> rating;

        std::cin.ignore(); 
        std::cout << "Enter review comments: ";
        std::getline(std::cin, comment);

        if (choice == 1) {
            reviews.addAtHead(rating, comment);
        } else {
            reviews.addAtTail(rating, comment);
        }

        std::cout << "Enter another review? Y/N: ";
        std::cin >> anotherReview;
    }

    std::cout << "Outputting all reviews:" << std::endl;
    reviews.outputReviews();

    return 0;
}
