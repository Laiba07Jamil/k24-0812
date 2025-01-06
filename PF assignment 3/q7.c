#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Content Information
typedef struct {
    char* contentTitle;
    double contentRating;
    int contentRuntime; // in minutes
    char* formatEncoding;
} ContentDetails;

// Structure for Device Preferences
typedef struct {
    int* screenResolutions;        // Array for resolution preferences
    double* dataUsageStats;        // Array for bandwidth usage statistics
} DeviceSettings;

// Structure for User Engagement Data
typedef struct {
    double** userEngagementScores; // 2D array for tracking user interactions
    int totalUsers;                // Number of users
    int totalCategories;           // Number of content categories
} EngagementMetrics;

// Structure for Device-Specific Preferences
typedef struct {
    DeviceSettings** userDevicePreferences; // 2D array for device preferences
    int totalDeviceTypes;                  // Number of device types
} DevicePreferencesInfo;

// Structure for Managing Content Metadata
typedef struct {
    ContentDetails** contentInformation; // 2D array for content metadata
    int totalCategories;                // Number of content categories
    int totalContentItems;              // Number of content items in each category
} ContentCatalog;

int main() {
    int totalUsers, totalCategories, totalDevices, totalContentItems;

    // Gather input data for the platform configuration
    printf("Please specify the total number of users: ");
    scanf("%d", &totalUsers);
    printf("How many content categories are there? ");
    scanf("%d", &totalCategories);
    printf("Enter the number of devices each user can have: ");
    scanf("%d", &totalDevices);
    printf("Enter the number of contents per category: ");
    scanf("%d", &totalContentItems);

    // Create engagement metrics system
    EngagementMetrics* userEngagement = (EngagementMetrics*)malloc(sizeof(EngagementMetrics));
    userEngagement->totalUsers = totalUsers;
    userEngagement->totalCategories = totalCategories;
    userEngagement->userEngagementScores = (double**)malloc(totalUsers * sizeof(double*));

    for (int i = 0; i < totalUsers; i++) {
        userEngagement->userEngagementScores[i] = (double*)calloc(totalCategories, sizeof(double));
    }

    // Create device preferences system
    DevicePreferencesInfo* devicePreferences = (DevicePreferencesInfo*)malloc(sizeof(DevicePreferencesInfo));
    devicePreferences->totalDeviceTypes = totalDevices;
    devicePreferences->userDevicePreferences = (DeviceSettings**)malloc(totalUsers * sizeof(DeviceSettings*));

    for (int i = 0; i < totalUsers; i++) {
        devicePreferences->userDevicePreferences[i] = (DeviceSettings*)malloc(totalDevices * sizeof(DeviceSettings));
        for (int j = 0; j < totalDevices; j++) {
            devicePreferences->userDevicePreferences[i][j].screenResolutions = (int*)calloc(1, sizeof(int)); // 1 resolution
            devicePreferences->userDevicePreferences[i][j].dataUsageStats = (double*)calloc(1, sizeof(double)); // 1 record
        }
    }

    // Create content catalog system
    ContentCatalog* contentCatalog = (ContentCatalog*)malloc(sizeof(ContentCatalog));
    contentCatalog->totalCategories = totalCategories;
    contentCatalog->totalContentItems = totalContentItems;
    contentCatalog->contentInformation = (ContentDetails**)malloc(totalCategories * sizeof(ContentDetails*));

    for (int i = 0; i < totalCategories; i++) {
        contentCatalog->contentInformation[i] = (ContentDetails*)malloc(totalContentItems * sizeof(ContentDetails));
        for (int j = 0; j < totalContentItems; j++) {
            contentCatalog->contentInformation[i][j].contentTitle = (char*)malloc(100 * sizeof(char));
            printf("Enter the title of content %d-%d (Category %d): ", j + 1, i + 1, i + 1);
            scanf("%s", contentCatalog->contentInformation[i][j].contentTitle);
            printf("Enter the rating (0-10) for content %s: ", contentCatalog->contentInformation[i][j].contentTitle);
            scanf("%lf", &contentCatalog->contentInformation[i][j].contentRating);
            printf("Enter the runtime in minutes for %s: ", contentCatalog->contentInformation[i][j].contentTitle);
            scanf("%d", &contentCatalog->contentInformation[i][j].contentRuntime);
            contentCatalog->contentInformation[i][j].formatEncoding = "H264";
        }
    }

    // Input user engagement data
    printf("\nPlease enter the engagement scores (0-100) for users in each content category:\n");
    for (int i = 0; i < totalUsers; i++) {
        for (int j = 0; j < totalCategories; j++) {
            printf("User %d, Category %d engagement score: ", i + 1, j + 1);
            scanf("%lf", &userEngagement->userEngagementScores[i][j]);
        }
    }

    // Input device preferences (resolution and bandwidth)
    printf("\nPlease specify the device preferences for each user and device:\n");
    for (int i = 0; i < totalUsers; i++) {
        for (int j = 0; j < totalDevices; j++) {
            printf("User %d, Device %d preferences:\n", i + 1, j + 1);
            printf("Enter the screen resolution (e.g., 1080 for Full HD): ");
            scanf("%d", &devicePreferences->userDevicePreferences[i][j].screenResolutions[0]);
            printf("Enter the estimated bandwidth usage (in Mbps): ");
            scanf("%lf", &devicePreferences->userDevicePreferences[i][j].dataUsageStats[0]);
        }
    }

    printf("\nExample: Engagement Score for User 1 in Category 2: %.2f\n", userEngagement->userEngagementScores[0][1]);

    printf("\n--- Displaying Content Metadata ---\n");
    for (int i = 0; i < totalCategories; i++) {
        for (int j = 0; j < totalContentItems; j++) {
            printf("Category %d, Content %d: Title = %s, Rating = %.1f, Runtime = %d minutes\n",
                   i + 1, j + 1, contentCatalog->contentInformation[i][j].contentTitle,
                   contentCatalog->contentInformation[i][j].contentRating,
                   contentCatalog->contentInformation[i][j].contentRuntime);
        }}
    for (int i = 0; i < totalUsers; i++) {
        free(userEngagement->userEngagementScores[i]);
        for (int j = 0; j < totalDevices; j++) 
        {
            free(devicePreferences->userDevicePreferences[i][j].screenResolutions);
            free(devicePreferences->userDevicePreferences[i][j].dataUsageStats);
        }
        free(devicePreferences->userDevicePreferences[i]);
    }
    free(userEngagement->userEngagementScores);
    free(userEngagement);

    for (int i = 0; i < totalCategories; i++) {
        for (int j = 0; j < totalContentItems; j++) {
            free(contentCatalog->contentInformation[i][j].contentTitle);
        }
        free(contentCatalog->contentInformation[i]);
    }
    free(contentCatalog->contentInformation);
    free(contentCatalog);

    free(devicePreferences->userDevicePreferences);
    free(devicePreferences);

    return 0;
}
